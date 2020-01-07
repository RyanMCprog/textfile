#include <iostream>
#include <fstream>
#include <string>

int main()
{
	int ScreenClose = 0;

	std::string options;
	std::string playerText;

	std::fstream file;


	

	while (ScreenClose == 0)
	{
		

		std::cout << "What do you want to do with the text file? display, write, clear, or exit" << std::endl;
		std::cin >> options;
		std::cout << std::endl;
		
		if (options == "display")
		{
			file.open("MyLog.txt", std::ios::in);

			if (!file.is_open())
			{
				std::cerr << "File not found." << std::endl;
				return -1;
			}

			std::string buffer;
			while (std::getline(file, buffer))
			{
				std::cout << buffer << std::endl;
			}

			file.close();

		}
		else if (options == "write")
		{
			file.open("MyLog.txt", std::ios::app);

			if (!file.is_open())
			{
				file.open("MyLog.txt", std::ios::out);
			}

			std::cout << "What do you want to write?" << std::endl;
			std::cin >> playerText;
			std::cout << std::endl;

			
			file << playerText;
			file << " ";

			file.close();
		}
		else if (options == "clear")
		{
			file.open("MyLog.txt", std::ios::out);

			file.clear();

			file.seekp(0, std::ios_base::end);

			file.close();
		}
		else if (options == "exit")
		{
			ScreenClose = 1;
		}

		options = " ";
	}
	file.close();
}