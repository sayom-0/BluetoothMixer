//
// Created by sjet on 8/13/20.
//

#include <iostream>
#include "GenericUi.h"

GenericUI::GenericUI(int row, int col)
{
	this->rows = row - 2;
	this->cols = col;
}

std::string GenericUI::getSelect(std::vector<std::string> list)
{
	int printed = 0;
	std::string window;
	std::string t;
	std::string title = "Select Device";
	std::vector<std::string> opt;
	for (int i = 0; i != list.size(); i++)
	{
		opt.push_back(std::to_string(i + 1) + ": " + list[i]);
	}

	for (int r = 0; r != this->rows; r++,
			window += "\n")
	{
		for (int c = 0; c != this->cols; c++)
		{
			t = ' ';
			if (r == 0 && c == 0)
			{
				t = '+';
			} else if (r == 0 && c == this->cols - 1)
			{
				t = '+';
			} else if (r == this->rows - 1 && c == 0)
			{
				t = '+';
			} else if (r == this->rows - 1 && c == this->cols - 1)
			{
				t = '+';
			} else if (r == 0 || r == this->rows - 1)
			{
				t = '-';
			} else if (c == 0 || c == this->cols - 1)
			{
				t = '|';
			} else if (c == int((this->cols - title.length()) * 0.5) && r == 1)
			{
				window += title;
				c += title.length();
			} else if (opt.size() != printed && r > 2 && c == int((this->cols - opt[printed].length()) * 0.5))
			{
				window += opt[printed];
				c += opt[printed].length();
				printed++;
			}

			window += t;
		}
	}

	return window;
}

std::string GenericUI::getMenu(const std::string &name, int select, const std::string &mdata) const
{
	std::string window;
	std::string t;

	for (int r = 0; r != this->rows; r++,
			window += "\n")
	{
		for (int c = 0; c != this->cols; c++)
		{
			t = ' ';
			if (r == 0 && c == 0)
			{
				t = '+';
			} else if (r == 0 && c == this->cols - 1)
			{
				t = '+';
			} else if (r == this->rows - 1 && c == 0)
			{
				t = '+';
			} else if (r == this->rows - 1 && c == this->cols - 1)
			{
				t = '+';
			} else if (r == 0 || r == this->rows - 1)
			{
				t = '-';
			} else if (c == 0 || c == this->cols - 1)
			{
				t = '|';
			} else if (c == int(this->cols * 0.12) && r == int(this->rows * 0.5))
			{
				if (select == 0)
				{
					t = '0';
				} else
				{
					t = 'O';
				}
			} else if (c == int(this->cols * 0.25) && r == int(this->rows * 0.25))
			{
				if (select == 0)
				{
					t = '0';
				} else
				{
					t = 'O';
				}
			} else if (c == int(this->cols * 0.25) && r == int(this->rows * 0.75))
			{
				if (select == 0)
				{
					t = '0';
				} else
				{
					t = 'O';
				}
			} else if (c == int(this->cols * 0.37) && r == int(this->rows * 0.25))
			{
				if (select == 1)
				{
					t = '0';
				} else
				{
					t = 'O';
				}
			} else if (c == int(this->cols * 0.37) && r == int(this->rows * 0.75))
			{
				if (select == 1)
				{
					t = '0';
				} else
				{
					t = 'O';
				}
			} else if (c == int(this->cols * 0.5) && r == int(this->rows * 0.25))
			{
				if (select == 1)
				{
					t = '0';
				} else
				{
					t = 'O';
				}
			} else if (c == int(this->cols * 0.5) && r == int(this->rows * 0.75))
			{
				if (select == 1)
				{
					t = '0';
				} else
				{
					t = 'O';
				}
			} else if (c == int(this->cols * 0.63) && r == int(this->rows * 0.5))
			{
				if (select == 1)
				{
					t = '0';
				} else
				{
					t = 'O';
				}
			} else if (c == int(this->cols * 0.75) && r == int(this->rows * 0.25))
			{
				if (select == 2)
				{
					t = '0';
				} else
				{
					t = 'O';
				}
			} else if (c == int(this->cols * 0.75) && r == int(this->rows * 0.75))
			{
				if (select == 2)
				{
					t = '0';
				} else
				{
					t = 'O';
				}
			} else if (c == int(this->cols * 0.87) && r == int(this->rows * 0.5))
			{
				if (select == 2)
				{
					t = '0';
				} else
				{
					t = 'O';
				}
			} else if (r == 1 && c == int((this->cols * 0.5) - name.length()))
			{
				window += name;
				c += name.length();
			} else if (r == int(this->rows * 0.8) && c == int((this->cols * 0.5) - mdata.length()))
			{
				window += mdata;
				c += mdata.length();
			}

			window += t;
		}
	}

	return window;
}

int GenericUI::getRows()
{
	return 0;
}

int GenericUI::getCols()
{
	return 0;
}

void GenericUI::setRows(int rows)
{
	this->rows = rows;
}

void GenericUI::setCols(int cols)
{
	this->cols = cols;
}
