#include <iostream>
#include <fstream>
#include <string>

struct bookInfo
{
	char callNumber[60];
	char title[60];
	char Author[60];
	char bookStatus[60];
	char dueDate[60];
	char borrowName[60];
};


int main()
{
	bookInfo cover[2];
	int count = sizeof(cover) / sizeof(bookInfo);

	std::fstream file;

	file.open("library.dat", std::ios_base::in | std::ios_base::binary);
	if (file.is_open())
	{	
		file.read((char*)&cover, sizeof(bookInfo)*3);
	
		file.close();
	}
	else
	{
		file.open("library.txt", std::ios_base::in);
		if (!file.is_open())
		{
			std::cout << "file not found" << std::endl;
			return 0;
		}
		else
		{
			std::fstream textfile;
			textfile.open("library.txt", std::ios::in);
			std::string tmp;
			
			for (int i = 0; i < count; ++i)
			{
				std::getline(textfile, tmp);
				strcpy_s(cover[i].callNumber, tmp.c_str());

				strcpy_s(cover[i].title, tmp.c_str());

				std::getline(textfile, tmp);
				strcpy_s(cover[i].Author, tmp.c_str());

				std::getline(textfile, tmp);
				strcpy_s(cover[i].bookStatus, tmp.c_str());

				if (cover[i].bookStatus == "2")
				{
					std::getline(textfile, tmp);
					strcpy_s(cover[i].dueDate, tmp.c_str());

					std::getline(textfile, tmp);
					strcpy_s(cover[i].borrowName, tmp.c_str());
				}
				
			}
			textfile.open("library.dat", std::ios_base::out | std::ios_base::binary);
			file.write((char*)&cover, sizeof(bookInfo) * 3);
			textfile.close();
		}
	}

	return 0;
}