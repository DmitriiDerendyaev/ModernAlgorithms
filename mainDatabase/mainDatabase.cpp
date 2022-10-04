// mainDatabase.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define _CRT_SECURE_NO_WARNINGS
#include "database.cpp"
#include <iostream>

enum userChoice { 
    MENU = 0, 
    DELETE = 1, 
    FIND_EMPTY = 2,
    ENTER = 3,
    SHOW = 4,
    SHOW_ALL = 5,
    FIND_NEAREST = 6,
    FIND_MIN = 7,
    SORT_ASC = 8,
    SORT_DESC = 9,
    READ = 10,
    WRITE = 11
};

void FiilingAllStructure(DataBase *currentBase, int sizeDB, char &buffer)
{
    for (int i = 0; i < sizeDB; i++)
    {
        BookField currentStructure;
        std::cout << "Page number: "; std::cin >> currentStructure.pageNumber;
        std::cout << "String number: "; std::cin >> currentStructure.stringNumber;
        std::cout << "Text of String: "; std::cin >> currentStructure.changedText;
        std::cout << "Date of change(dd.mm.yyyy): "; std::cin >> currentStructure.ChangedTimeInstance.year >> buffer >>
            currentStructure.ChangedTimeInstance.mounth >> buffer >> currentStructure.ChangedTimeInstance.mounth;
        currentBase->AddBook(currentStructure, i);
        std::cout << "Added! " << std::endl;
    }
}

void FiilingStructure(DataBase* currentBase, int indexElement, char& buffer)
{
    BookField currentStructure;
    std::cout << "Page number: "; std::cin >> currentStructure.pageNumber;
    std::cout << "String number: "; std::cin >> currentStructure.stringNumber;
    std::cout << "Text of String: "; std::cin >> currentStructure.changedText;
    std::cout << "Date of change(dd.mm.yyyy): "; std::cin >> currentStructure.ChangedTimeInstance.year >> buffer >>
    currentStructure.ChangedTimeInstance.mounth >> buffer >> currentStructure.ChangedTimeInstance.mounth;
    currentBase->AddBook(currentStructure, indexElement);
    std::cout << "Added! " << std::endl;
}

void PrintStructure(DataBase* currentBase, int indexStructure, char& buffer)
{
    BookField currentBook = currentBase->ExtractBook(indexStructure);
    std::cout << "Page number: " << currentBook.pageNumber << std::endl;
    std::cout << "String number: " << currentBook.stringNumber << std::endl;
    std::cout << "Text of String: " << currentBook.changedText << std::endl;
    std::cout << "Date of change(dd.mm.yyyy): " << currentBook.ChangedTimeInstance.year << buffer <<
        currentBook.ChangedTimeInstance.mounth << buffer << currentBook.ChangedTimeInstance.mounth << std::endl;
}

void PrintAllStructure(DataBase* currentBase, int indexStructure, char& buffer)
{
    std::vector<BookField> allList = currentBase->GetAllBook();
    for (int i = 0; i < allList.size(); i++)
    {
        std::cout << "Page number: " << allList[i].pageNumber << std::endl;
        std::cout << "String number: " << allList[i].stringNumber << std::endl;
        std::cout << "Text of String: " << allList[i].changedText << std::endl;
        std::cout << "Date of change(dd.mm.yyyy): " << allList[i].ChangedTimeInstance.year << buffer <<
            allList[i].ChangedTimeInstance.mounth << buffer << allList[i].ChangedTimeInstance.mounth << std::endl << std::endl;
    }
}

void DeleteElement(DataBase *currentBase, int indexElement)
{
    currentBase->DeleteStructure(indexElement);
    std::cout << "Structure(" << indexElement << ") was deleted." << std::endl;
}

int main()
{   
    
    int sizeDB, userChoice;
    int indexElement = 0;
    std::cout << "Enter a size of DB: ";
    std::cin >> sizeDB;
    DataBase* currentBase = new DataBase("myDB", sizeDB, "myDB.bin");
    char buffer;

    std::cout << " MENU = 0,\n DELETE = 1,\n FIND_EMPTY = 2,\n ENTER = 3,\n SHOW = 4,\n SHOW_ALL = 5,\n FIND_NEAREST = 6,\n FIND_MIN = 7,\n SORT_ASC = 8," << std::endl <<
        "SORT_DESC = 9,\n READ = 10,\n WRITE = 11" << std::endl;

    while (true)
    {
        std::cin >> userChoice;
        switch (userChoice)
        {
        case DELETE:
        {
            try
            {
                std::cout << "Enter index of element to delete it: ";
                std::cin >> indexElement;
                DeleteElement(currentBase, indexElement);
            }
            catch (const std::out_of_range& error)
            {
                std::cerr << "Out of range Error: " << error.what() << std::endl;
            }
            break;
        }
        case FIND_EMPTY:
        {
            try
            {
                indexElement = currentBase->FindEmptyBook();
                std::cout << "Index of empty element: " << indexElement << std::endl;
                PrintStructure(currentBase, indexElement, buffer);
                std::cout << std::endl;
            }
            catch (const std::out_of_range& error)
            {
                std::cerr << "Out of range Error: " << error.what() << std::endl;
            }
            break;
        }
        case ENTER:
        {
            try
            {
                std::cout << "Enter index of element to fill it: ";
                std::cin >> indexElement;
                FiilingStructure(currentBase, indexElement, buffer);
            }
            catch (const std::out_of_range& error)
            {
                std::cerr << "Out of range Error: " << error.what() << std::endl;
            }
            break;
        }
        case SHOW:
        {
            try
            {
                std::cout << "Enter index of element to show it: ";
                std::cin >> indexElement;
                PrintStructure(currentBase, indexElement, buffer);
                std::cout << std::endl;
            }
            catch (const std::logic_error& error)
            {
                std::cerr << "Logic Error: " << error.what() << std::endl;
            }
            break;
        }

        case SHOW_ALL:
        {
            try
            {
                PrintStructure(currentBase, indexElement, buffer);
                std::cout << std::endl;
            }
            catch (const std::out_of_range& error)
            {
                std::cerr << "Out of range Error: " << error.what() << std::endl;
            }
            break;
        }
        case FIND_NEAREST:
        {
            try
            {
                int searchingPage;
                std::cout << "Page to search: ";
                std::cin >> searchingPage;
                auto selectorFunction = [](BookField p) { return p.pageNumber; };
                BookField* resByInt = currentBase->FindNearestInt(selectorFunction, searchingPage);
                if (resByInt == NULL)
                    std::cout << "NotFound!" << std::endl;
                else
                    std::cout << resByInt->pageNumber << std::endl << " " << resByInt->stringNumber << std::endl << " " << resByInt->changedText << std::endl << std::endl;
            }
            catch (const std::logic_error& error)
            {
                std::cerr << "Logical Error: " << error.what() << std::endl;
            }
            break;
        }
        case FIND_MIN:
        {
            try
            {
                BookField* minByString = currentBase->FindMinField<int>([](BookField p) { return p.stringNumber; });
                std::cout << "Min by String: " << std::endl << minByString->pageNumber << std::endl << " " << minByString->stringNumber << std::endl << " " << minByString->changedText << std::endl;

            }
            catch (const std::logic_error& error)
            {
                std::cerr << "Logical Error: " << error.what() << std::endl;
            }
            break;
        }
        case SORT_ASC:
        {
            try
            {
                auto selectorSortFunction = [](BookField firstField, BookField secondField) { return ((firstField.pageNumber) > (secondField.pageNumber)); };
                currentBase->SortBy(selectorSortFunction);
                std::cout << "Sorted by Number of Page: ascend " << std::endl;
            }
            catch (const std::logic_error& error)
            {
                std::cerr << "Logical Error: " << error.what() << std::endl;
            }
            break;
        }
        case SORT_DESC:
        {
            try
            {
                auto selectorSortFunction = [](BookField firstField, BookField secondField) { return ((firstField.pageNumber) < (secondField.pageNumber)); };
                currentBase->SortBy(selectorSortFunction);
                std::cout << "Sorted by Number of Page: descend " << std::endl;
            }
            catch (const std::logic_error& error)
            {
                std::cerr << "Logical Error: " << error.what() << std::endl;
            }
            break;
        }
        case READ:
        {
            try
            {
                currentBase->Read();
                std::cout << "Has been read!" << std::endl;
            }
            catch (const std::logic_error& error)
            {
                std::cerr << "Logical Error: " << error.what() << std::endl;
            }
            break;
        }
        case WRITE:
        {
            try
            {
                currentBase->Save();
                std::cout << "Saved!" << std::endl;
            }
            catch (const std::logic_error& error)
            {
                std::cerr << "Logical Error: " << error.what() << std::endl;
            }
            break;
        }
        default:
            break;
        }
        std::cout << " MENU = 0,\n DELETE = 1,\n FIND_EMPTY = 2,\n ENTER = 3,\n SHOW = 4,\n SHOW_ALL = 5,\n FIND_NEAREST = 6,\n FIND_MIN = 7,\n SORT_ASC = 8," << std::endl <<
            "SORT_DESC = 9,\n READ = 10,\n WRITE = 11" << std::endl;
    }
    
    return 0;
}
