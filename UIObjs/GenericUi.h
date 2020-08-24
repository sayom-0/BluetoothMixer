//
// Created by sjet on 8/13/20.
//

#ifndef BLUETOOTHMIXER_GENERICUI_H
#define BLUETOOTHMIXER_GENERICUI_H


#include <string>
#include <vector>

class GenericUI
{
private:
	int rows{}, cols{};
public:
	std::string
	getMenu(std::string name, int select, std::string mdata, bool playing, std::string time, std::string ctime,
			double progress, double vol);

	std::string getSelect(std::vector<std::string> list);

	GenericUI(int row, int col);

	int getRows();

	int getCols();

	void setRows(int);

	void setCols(int);
};


#endif //BLUETOOTHMIXER_GENERICUI_H
