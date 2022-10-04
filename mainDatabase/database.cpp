//3 training variant
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <String>
#include <vector>
#include <tuple>

#include <stdexcept>



struct ChangeTime {
	int year;
	int mounth;
	int day;
};

struct BookField {
	int pageNumber;
	int stringNumber;
	std::string changedText;
	ChangeTime ChangedTimeInstance;

	bool isEmpty;

	template<size_t I>
	auto& get() {
		return std::get<I>(std::tie(pageNumber, stringNumber, changedText, ChangedTimeInstance));
	}
};

class DataBase
{
private:
	BookField *_arrayOfBook;
	long _databaseSize;
	std::string _databaseName;
	std::string _databasePath;

	template<typename TempStruct>
	void swap(TempStruct* xp, TempStruct* yp)
	{
		TempStruct temp = *xp;
		*xp = *yp;
		*yp = temp;
	}

public:
	DataBase(std::string databaseName, int databaseSize, std::string databasePath) {
		_arrayOfBook = new BookField[databaseSize];
		_databaseName = databaseName;
		_databaseSize = databaseSize;
		_databasePath = databasePath;

		for (int i = 0; i < _databaseSize; i++)
		{
			_arrayOfBook[i].isEmpty = true;
		}
	}

	DataBase() {
		_arrayOfBook = new BookField[3];
		_databaseName = "MyDB";
		_databaseSize = 3;
		_databasePath = "MyDB.bin";

		for (int i = 0; i < _databaseSize; i++)
		{
			_arrayOfBook[i].isEmpty = true;
		}
	}

	~DataBase() {
		delete[] _arrayOfBook;
	}

	void DeleteStructure(int indexBook) {
		if (indexBook > _databaseSize || indexBook < 0)
		{
			throw std::out_of_range("Out of array!");
		}
		else
		{
			_arrayOfBook[indexBook].isEmpty = true;
		}
	}

	int FindEmptyBook()
	{
		int functionStatus = -1;
		for (int i = 0; i < _databaseSize; i++)
		{
			if (_arrayOfBook[i].isEmpty)
			{
				functionStatus = i;
				break;
			}			
		}
		if (functionStatus == -1)
		{
			throw std::underflow_error("There are no empty elements!");
			return -1;
		}
		else
		{
			return functionStatus;
		}

	}

	void AddBook(BookField currentBook, int indexOfBook)
	{
		if (indexOfBook >= _databaseSize || indexOfBook < 0)
		{
			throw std::out_of_range("Out of array!");
		}
		else
		{
			_arrayOfBook[indexOfBook] = currentBook;
			_arrayOfBook[indexOfBook].isEmpty = false;
		}
		
	}

	BookField ExtractBook(int indexOfBook)
	{
		if (indexOfBook >= _databaseSize || indexOfBook < 0)
		{
			throw std::out_of_range("Out of array!");
		}
		else
		{
			return _arrayOfBook[indexOfBook];
		}
	}

	std::vector<BookField> GetAllBook()
	{
		std::vector<BookField> getResult;
		bool allStructureEmpty = true;
		for (int i = 0; i < _databaseSize; i++)
		{
			if (_arrayOfBook[i].isEmpty == false)
			{
				getResult.push_back(_arrayOfBook[i]);
				allStructureEmpty = false;
			}
		}
		if(allStructureEmpty == false)
			return getResult;
		else
			throw std::logic_error("Empty structure");
	}

	BookField* FindNearestInt(int (*selectorFunction)(BookField), int searchingElement)
	{
		int indexOfNearestElement = -1;
		int minimalDiff = INT_MAX;

		for (size_t i = 0; i < _databaseSize; i++)
			if (!_arrayOfBook[i].isEmpty) {
				int valueDiff = abs(selectorFunction(_arrayOfBook[i]) - searchingElement);

				if (valueDiff < minimalDiff) {
					minimalDiff = valueDiff;
					indexOfNearestElement = i;
				}
			}
		if (indexOfNearestElement == -1)
		{
			throw std::logic_error("No matches by Int!");
			return (BookField*)NULL;
		}
		else
		{
			return &_arrayOfBook[indexOfNearestElement];
		}
	}

	BookField* FindNearestString(int (*selectorFunction)(BookField), std::string searchingString)
	{
		for (int elementIndex = 0; elementIndex < _databaseSize; elementIndex++)
		{
			if (_arrayOfBook[elementIndex].isEmpty == true) continue;
			if (std::string(_arrayOfBook[elementIndex].changedText).find(searchingString) != std::string::npos) {
				return &_arrayOfBook[elementIndex];
			}
		}
		return NULL;
	}

	template<typename UniversalType>	
	BookField* FindMinField(int (*selectorFunction)(BookField))
	{
		UniversalType currentMin = selectorFunction(_arrayOfBook[0]);
		int indexOfMinimalElementDefault = -1;
		for (int i = 0; i < _databaseSize; i++)
			if (!_arrayOfBook[i].isEmpty && selectorFunction(_arrayOfBook[i]) <= currentMin)
			{
				indexOfMinimalElementDefault = i;
				currentMin = selectorFunction(_arrayOfBook[i]);
			}
		if (indexOfMinimalElementDefault == -1)
		{
			throw std::logic_error("No matches by Int!");
			return (BookField*)NULL;
		}
		else
		{
			return &_arrayOfBook[indexOfMinimalElementDefault];
		}
	}
	template<typename UniversalType>
	BookField* FindMinByNumber(int fieldNumber)
	{
		UniversalType currentMin = _arrayOfBook[0].get<0>();
		int indexOfMinimalElementDefault = -1;
		for (int i = 0; i < _databaseSize; i++)
		{
			if (_arrayOfBook[i].isEmpty == false && _arrayOfBook[i].get<fieldNumber>() <= currentMin)
			{
				indexOfMinimalElementDefault = i;
				currentMin = _arrayOfBook[i].get<fieldNumber>();
			}
		}
		if (indexOfMinimalElementDefault == -1)
		{
			throw std::logic_error("No matches by Int!");
			return (BookField)NULL;
		}
		else
		{
			return &_arrayOfBook[indexOfMinimalElementDefault];
		}
	}
	//bubble sort
	/*template<typename UniversalType>
	void SortBy(bool (*descOrAsc)(BookField, BookField)) {
		for (int i = 0; i < _databaseSize - 1; i++)
			for (int j = 0; j < _databaseSize - i - 1; j++)
				if (descOrAsc(_arrayOfBook[j], _arrayOfBook[j + 1]))
				{
					UniversalType temp = (*_arrayOfBook)[j];
					(*_arrayOfBook)[j] = (*_arrayOfBook)[j + 1];
					(*_arrayOfBook)[j + 1] = temp;
				}
	}*/

	void SortBy(bool (*descOrAsc)(BookField, BookField)) {
		for (int i = 0; i < _databaseSize - 1; i++)
			for (int j = 0; j < _databaseSize - i - 1; j++)
				if (descOrAsc(_arrayOfBook[j], _arrayOfBook[j + 1]) == 0 || descOrAsc(_arrayOfBook[j], _arrayOfBook[j + 1]) == 1)
					if (descOrAsc(_arrayOfBook[j], _arrayOfBook[j + 1]))
					{
						swap(&_arrayOfBook[j], &_arrayOfBook[j + 1]);
					}
					else
						throw std::logic_error("Unexpected error!");
		
	}
	void Read() {
		const char* pathFile = _databasePath.c_str();
		FILE* file = fopen(pathFile, "rb");

		for (size_t i = 0; i < _databaseSize; i++)
			fread(&_arrayOfBook[i], sizeof(BookField), 1, file);

		fclose(file);
	}

	void Save() {
		//const char* pathFile = _databasePath.c_str();
		FILE* file = fopen("myDB.bin", "rb");

		for (size_t i = 0; i < _databaseSize; i++)
			fwrite(&_arrayOfBook[i], sizeof(BookField), 1, file);

		fclose(file);
	}





};