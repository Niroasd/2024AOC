#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool threshold(int curr, int old);
bool isSafe(const vector<int> &levels);
bool canBeSafeByRemovingOne(const vector<int> &levels);

int main()
{
    string line;
    int curr = 0, safe = 0;

    try
    {
        ifstream MyReadFile("input.txt");

        while (getline(MyReadFile, line))
        {
            vector<int> levels;
            istringstream myStream(line);

            while (myStream >> curr)
            {
                levels.push_back(curr);
            }

            if (isSafe(levels))
            {
                safe++;
            }
            else if (canBeSafeByRemovingOne(levels))
            {
                safe++;
            }
        }
        MyReadFile.close();
        cout << "Final safe reports count: " << safe << endl;
    }
    catch (const exception &e)
    {
        cerr << e.what() << '\n';
    }

    return 0;
}

bool threshold(int curr, int old)
{
    return (abs(curr - old) <= 3);
}

bool isSafe(const vector<int> &levels)
{
    int fail = 0;
    bool asc = true;
    int old = levels[0];

    for (int i = 1; i < levels.size(); i++)
    {
        int curr = levels[i];

        if (!threshold(curr, old))
        {
            fail++;
            old = curr;
            continue;
        }

        if (i == 1)
        {
            if (curr > old)
                asc = true;
            else if (curr < old)
                asc = false;
        }

        if (asc && !(curr > old))
        {
            fail++;
        }
        else if (!asc && !(curr < old))
        {
            fail++;
        }

        old = curr;
    }

    return fail == 0;
}

bool canBeSafeByRemovingOne(const vector<int> &levels)
{
    for (int i = 0; i < levels.size(); i++)
    {
        vector<int> levelsCopy = levels;
        levelsCopy.erase(levelsCopy.begin() + i);

        if (isSafe(levelsCopy))
        {
            return true;
        }
    }
    return false;
}
