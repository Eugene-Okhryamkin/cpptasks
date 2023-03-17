#include <iostream>
#include <vector>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *b;
    *b = *a;
    *a = temp;
}
void heapify(vector<int> &hT, int i)
{
    int size = hT.size();
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < size && hT[l] > hT[largest])
        largest = l;
    if (r < size && hT[r] > hT[largest])
        largest = r;

    if (largest != i)
    {
        swap(&hT[i], &hT[largest]);
        heapify(hT, largest);
    }
}

void insert(vector<int> &hT, int newNum)
{
    int size = hT.size();
    if (size == 0)
    {
        hT.push_back(newNum);
    }
    else
    {
        hT.push_back(newNum);
        for (int i = size / 2 - 1; i >= 0; i--)
        {
            heapify(hT, i);
        }
    }
}

void printArray(vector<int> &hT)
{
    for (int i = 0; i < hT.size(); ++i)
        cout << hT[i] << " ";
    cout << "\n";
}

vector<int> printVector(vector<vector<int>> &hT)
{
    vector<int> solution;
    for (int i = 0; i < hT.size(); i++)
    {
        vector<int> current = hT.at(i);
        int sol = 1;
        for (int j = 1; j < current.size(); j++) {
            if(current.at(j) > 0 && current.at(j-1) < 0 || current.at(j) < 0 && current.at(j-1) > 0) {

            } else {
                sol = 0;
                break;
            }
        }
        solution.push_back(sol);
    }

    return solution;
}

int main()
{
    vector<vector<int>> sum;

    for (;;) {
        cout << ">";
        int comm;
        cin >> comm;
        if(comm<0 || comm>4){
            cout << "error, use 0 to help \n";
        }
        if(comm==0){
            cout << "0 - help, 1 - add element, 2 - build vector, 3 - show inserted , 4 - stop app \n";
        }
        if(comm==1) {
            vector<int> heapTree;
            cout << "length of input: ";
            int len;
            cin >> len;

            for (int i = 0; i < len; i++)
            {
                int element = 0;
                cout << "[" << i << "] = ";
                cin >> element;
                insert(heapTree, element);
            }
            sum.push_back(heapTree);
        }
        if(comm==2) {
            vector<int> solution = printVector(sum);
            printArray(solution);
        }
        if(comm==3) {
            for(int i = 0; i < sum.size(); i++) {
                printArray(sum.at(i));
            }
        }
        if(comm==4) {
            break;
        }
    }
}