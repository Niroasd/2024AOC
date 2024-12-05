#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

using namespace std;

void fillVector(vector<vector<char>> &vectorContainer);
int searchXmas();

int main()
{
    vector<vector<char>> vectorContainer;

    fillVector(vectorContainer);

    for (int k = 0; k < vectorContainer.size(); k++)
    {
        cout << vectorContainer[0][k] << endl;
    }
    cout << "first row of the vector" << endl;
    return 0;
}

void fillVector(vector<vector<char>> &vectorContainer)
{
    string line;

    char curr;
    int i = 0, j = 0;
    try
    {
        ifstream myFile("input.txt");

        while (getline(myFile, line))
        {
            istringstream myStream(line);
            vector<char> tempRow;

            while (myStream >> curr)
            {
                tempRow.push_back(curr);
            }
            vectorContainer.push_back(tempRow);
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}