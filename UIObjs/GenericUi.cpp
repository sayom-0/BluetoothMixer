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

std::string
GenericUI::getMenu(std::string name, int select, std::string mdata, bool playing, std::string time, std::string ctime,
				   double progress)
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
			} else if (r == 1 && c == int((this->cols * 0.5) - (name.length() * 0.5)))
			{
				window += name;
				c += name.length();
			} else if (r == int(this->rows * 0.8) && c == int((this->cols * 0.5) - (mdata.length() * 0.5)))
			{
				window += mdata;
				c += mdata.length();
			} else if (r == int(this->rows * 0.85) && c == int(this->cols * 0.1))
			{
				window += "|";
				int slots = int(this->cols * 0.1) - int(this->cols * 0.9);
				slots *= -1;
				slots += int(this->cols * 0.1) * 2;
				for (; c != int(this->cols * 0.9); c++)
				{
					if (c == int(slots * progress))
					{
						window += 'O';
					} else
					{
						window += "-";
					}
				}
				c += 2;
				window += "|";
			} else if (r == int(this->rows * 0.85) + 1 && c == int(this->cols * 0.1))
			{
				window += ctime;
				c += ctime.length();
			} else if (r == int(this->rows * 0.85) + 1 && c == int(this->cols * 0.9))
			{
				window += time;
				c += time.length();
			} else if (r == 3 && c == int((this->cols * 0.5) - (std::string("Playing").length() * 0.5)) && playing)
			{
				window += "Playing";
				c += std::string("Playing").length();
			} else if (r == 3 && c == int((this->cols * 0.5) - (std::string("Paused").length() * 0.5)) && !playing)
			{
				window += "Paused";
				c += std::string("Paused").length();
			}

			window += t;
		}
	}

	return window;
}

int GenericUI::getRows()
{
	return this->rows;
}

int GenericUI::getCols()
{
	return this->cols;
}

void GenericUI::setRows(int rows)
{
	this->rows = rows - 2;
}

void GenericUI::setCols(int cols)
{
	this->cols = cols;
}
