#include "CalculatorProcessor.h"
#include <stack>
#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <sstream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <cstdlib>


CalculatorProcessor* CalculatorProcessor::_calculatorProcessor = nullptr;

CalculatorProcessor* CalculatorProcessor::GetInstance()
{
	if (_calculatorProcessor == nullptr)
	{
		_calculatorProcessor = new CalculatorProcessor();
	}
	return _calculatorProcessor;
}

double CalculatorProcessor::Calculate(std::string calc)
{
	ClearCalculator();

	if (error == "error")
	{
		ClearError();
	}

	std::string str = ConvertString(calc);

	GenerateTokens(str);

	for (int i = 0; i < tokens.size(); i++)
	{
		if (tokens[i][0] == '0' ||
			tokens[i][0] == '1' ||
			tokens[i][0] == '2' ||
			tokens[i][0] == '3' ||
			tokens[i][0] == '4' ||
			tokens[i][0] == '5' ||
			tokens[i][0] == '6' ||
			tokens[i][0] == '7' ||
			tokens[i][0] == '8' ||
			tokens[i][0] == '9')
		{
			output.push(tokens[i]);
		}
		if (tokens[i] == "Sin" ||
			tokens[i] == "Cos" ||
			tokens[i] == "Tan")
		{
			operators.push(tokens[i]);
		}
		if (tokens[i] == "+" ||
			tokens[i] == "-" ||
			tokens[i] == "*" ||
			tokens[i] == "/" ||
			tokens[i] == "%")
		{
			if (!operators.empty())
			{
				while (operators.top() == "+" ||
					operators.top() == "-" ||
					operators.top() == "/" ||
					operators.top() == "*" ||
					operators.top() == "%" &&
					operators.top() != "(")
				{
					if (tokens[i] == "*" &&
						operators.top() == "+")
					{
						break;
					}
					if (tokens[i] == "*" &&
						operators.top() == "-")
					{
						break;
					}
					if (tokens[i] == "*" &&
						operators.top() == "/")
					{
						std::string value = operators.top();
						operators.pop();
						output.push(value);
						break;
					}
					if (tokens[i] == "*" &&
						operators.top() == "%")
					{
						std::string value = operators.top();
						operators.pop();
						output.push(value);
						break;
					}
					if (tokens[i] == "*" &&
						operators.top() == "*")
					{
						std::string value = operators.top();
						operators.pop();
						output.push(value);
						break;
					}
					if (tokens[i] == "+" &&
						operators.top() == "-")
					{
						std::string value = operators.top();
						operators.pop();
						output.push(value);
						break;
					}
					if (tokens[i] == "+" &&
						operators.top() == "+")
					{
						std::string value = operators.top();
						operators.pop();
						output.push(value);
						break;
					}
					if (tokens[i] == "+" &&
						operators.top() == "*")
					{
						std::string value = operators.top();
						operators.pop();
						output.push(value);
						break;
					}
					if (tokens[i] == "+" &&
						operators.top() == "/")
					{
						std::string value = operators.top();
						operators.pop();
						output.push(value);
						break;
					}
					if (tokens[i] == "+" &&
						operators.top() == "%")
					{
						std::string value = operators.top();
						operators.pop();
						output.push(value);
						break;
					}
					if (tokens[i] == "-" &&
						operators.top() == "+")
					{
						std::string value = operators.top();
						operators.pop();
						output.push(value);
						break;
					}
					if (tokens[i] == "-" &&
						operators.top() == "-")
					{
						std::string value = operators.top();
						operators.pop();
						output.push(value);
						break;
					}
					if (tokens[i] == "-" &&
						operators.top() == "*")
					{
						std::string value = operators.top();
						operators.pop();
						output.push(value);
						break;
					}
					if (tokens[i] == "-" &&
						operators.top() == "/")
					{
						std::string value = operators.top();
						operators.pop();
						output.push(value);
						break;
					}
					if (tokens[i] == "-" &&
						operators.top() == "%")
					{
						std::string value = operators.top();
						operators.pop();
						output.push(value);
						break;
					}
					if (tokens[i] == "/" &&
						operators.top() == "+")
					{
						break;
					}
					if (tokens[i] == "/" &&
						operators.top() == "-")
					{
						break;
					}
					if (tokens[i] == "/" &&
						operators.top() == "*")
					{
						std::string value = operators.top();
						operators.pop();
						output.push(value);
						break;
					}
					if (tokens[i] == "/" &&
						operators.top() == "%")
					{
						std::string value = operators.top();
						operators.pop();
						output.push(value);
						break;
					}
					if (tokens[i] == "/" &&
						operators.top() == "/")
					{
						std::string value = operators.top();
						operators.pop();
						output.push(value);
						break;
					}
					if (tokens[i] == "%" &&
						operators.top() == "+")
					{
						break;
					}
					if (tokens[i] == "%" &&
						operators.top() == "-")
					{
						break;
					}
					if (tokens[i] == "%" &&
						operators.top() == "*")
					{
						std::string value = operators.top();
						operators.pop();
						output.push(value);
						break;
					}
					if (tokens[i] == "%" &&
						operators.top() == "/")
					{
						std::string value = operators.top();
						operators.pop();
						output.push(value);
						break;
					}
					if (tokens[i] == "%" &&
						operators.top() == "%")
					{
						std::string value = operators.top();
						operators.pop();
						output.push(value);
						break;
					}
					if (operators.empty())
					{
						break;
					}
				}
			}

			operators.push(tokens[i]);
		}
		if (tokens[i] == "(")
		{
			operators.push(tokens[i]);
		}
		if (tokens[i] == ")")
		{
			while (operators.top() != "(")
			{
				if (!operators.empty())
				{
					std::string value = operators.top();
					operators.pop();
					output.push(value);
				}
				if (operators.empty())
				{
					error = "error";
					break;
				}
			}
			if (operators.empty())
			{
				error = "error";
				break;
			}
			if (operators.top() == "(")
			{
				operators.pop();
			}
			if (!operators.empty())
			{
				if (operators.top() == "Sin" ||
					operators.top() == "Cos" ||
					operators.top() == "Tan")
				{
					std::string value = operators.top();
					operators.pop();
					output.push(value);
				}
			}
		}


	}
	while (!operators.empty())
	{
		if (operators.top() == ")" || operators.top() == "(")
		{
			error = "error";
			break;
		}
		if (operators.top() != "(")
		{
			std::string value = operators.top();
			operators.pop();
			output.push(value);
		}
	}
	SolveRPN();

	return answer;
}

void CalculatorProcessor::GenerateTokens(std::string calc)
{
	std::istringstream iss(calc);

	std::string s;
	while (iss >> s)
	{
		tokens.push_back(s);
	}
}

std::string CalculatorProcessor::ConvertString(std::string str)
{
	std::string temp = str;

	for (int i = 0; i < temp.size(); i++)
	{
		if (temp[i] == '+' ||
			temp[i] == '*' ||
			temp[i] == '(' ||
			temp[i] == ')' ||
			temp[i] == '/' ||
			temp[i] == '%' ||
			temp[i] == '-')
		{
			temp.insert(i, 1, ' ');
			temp.insert(i + 2, 1, ' ');
			i += 2;
		}
	}
	return temp;
}

void CalculatorProcessor::SolveRPN()
{

	while (!output.empty())
	{

		std::string front = output.front();
		if (front[0] == '0' ||
			front[0] == '1' ||
			front[0] == '2' ||
			front[0] == '3' ||
			front[0] == '4' ||
			front[0] == '5' ||
			front[0] == '6' ||
			front[0] == '7' ||
			front[0] == '8' ||
			front[0] == '9')
		{
			double num = std::stof(output.front());
			out.push_back(num);
			output.pop();
		}
		else
		{
			if (output.front() == "Sin")
			{
				double xDegrees = out.back();
				out.pop_back();
				out.push_back(sin(xDegrees));
				output.pop();
				continue;
				if (output.empty())
				{
					break;
				}
			}
			else if (output.front() == "Cos")
			{
				double xDegrees = out.back();
				out.pop_back();
				out.push_back(cos(xDegrees));
				output.pop();
				continue;
				if (output.empty())
				{
					break;
				}
			}
			else if (output.front() == "Tan")
			{
				double xDegrees = out.back();
				out.pop_back();
				out.push_back(tan(xDegrees));
				output.pop();
				continue;
				if (output.empty())
				{
					break;
				}
			}
			double secondOperand = out.back();
			out.pop_back();
			double firstOperand = out.back();
			out.pop_back();
			if (output.front() == "*")
			{
				out.push_back(firstOperand * secondOperand);
				output.pop();
			}

			else if (output.front() == "/")
			{
				out.push_back(firstOperand / secondOperand);
				output.pop();
			}

			else if (output.front() == "-")
			{
				out.push_back(firstOperand - secondOperand);
				output.pop();
			}

			else if (output.front() == "+")
			{
				out.push_back(firstOperand + secondOperand);
				output.pop();
			}
			else if (output.front() == "%")
			{
				out.push_back((int)firstOperand % (int)secondOperand);
				output.pop();
			}
		}
	}

	if (error == "error")
	{
		error = "none";
		out.push_back(0);
	}

	answer = out.back();
}

void CalculatorProcessor::ClearError()
{
	tokens.clear();
	out.clear();
	for (int i = 0; i < operators.size(); i++)
	{
		operators.pop();
	}
	for (int i = 0; i < output.size(); i++)
	{
		output.pop();
	}
	error = "none";
}

void CalculatorProcessor::ClearCalculator()
{

	if (!tokens.empty())
	{
		tokens.clear();
		out.clear();
	}
}
