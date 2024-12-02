#include <string>
#include <sstream>
#include <fstream>
#include <iostream>

using namespace std;

bool threshold(int curr, int old);

int main()
{
    string line;
    int curr = 0, old = 0, iter = 0, fail = 0, safe = 0;
    bool asc = true;

    try
    {
        ifstream MyReadFile("input.txt");

        while (getline(MyReadFile, line))
        {
            curr = old = iter = fail = 0;
            asc = true;
            istringstream myStream(line);
            while (myStream >> curr)
            {
                if (iter == 1)
                {
                    if (curr > old)
                    {
                        asc = true;
                        cout << "set to asc" << "curr: " << curr << " old: " << old << endl;
                    }
                    else
                    {
                        asc = false;
                        cout << "set to desc" << endl;
                    }
                }

                if (iter > 0)
                {
                    if (!threshold(curr, old) || (fail != 0))
                    {
                        cout << "broke threshold or failed ascdesc" << endl;
                        fail++;
                        break;
                    }

                    if (curr == old)
                    {
                        cout << "numbers are equal" << endl;
                        fail++;
                        break;
                    }

                    if (asc && !(curr > old))
                    {
                        cout << curr << "not ascending, breaking loop" << old << endl;
                        fail++;
                        break;
                    }

                    if (!asc && !(old > curr))
                    {
                        cout << curr << "not descending, breaking loop" << old << endl;
                        fail++;
                        break;
                    }

                    cout << curr << " < curr - old > " << old << endl;
                }

                iter++;

                old = curr;
            }
            if (fail == 0)
            {
                safe++;
            }
            cout << "end of line" << endl;
        }
        MyReadFile.close();
        cout << "final score and end of file \t" << safe << endl;
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