#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

int main()
{
    int size = 1000;
    string line, value;
    vector<int> nums1;
    vector<int> nums2;
    int distance, similarity = 0;

    try
    {
        ifstream MyReadFile("01data.txt");
        MyReadFile.exceptions(MyReadFile.badbit);

        while (getline(MyReadFile, line))
        {
            istringstream myStream(line);
            int temp;
            myStream >> temp;
            nums1.push_back(temp);
            myStream >> temp;
            nums2.push_back(temp);
        }
        MyReadFile.close();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    int j = 0;
    //similarity score
    for (j; j < nums1.size(); j++)
    {
        similarity += nums1[j] * count(nums2.begin(), nums2.end(), nums1[j]);
    }

    //distance
    while (nums1.size() > 0 && nums2.size() > 0)
    {
        auto iterator1 = min_element(nums1.begin(), nums1.end());
        auto iterator2 = min_element(nums2.begin(), nums2.end());
        distance += abs(*iterator1 - *iterator2);

        nums1.erase(iterator1);
        nums2.erase(iterator2);
    }

    cout << "distance: " << distance << "\n" << "similarity score: " << similarity << endl;

    return 0;
}