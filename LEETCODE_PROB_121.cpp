#include <iostream>
using namespace std;
int maxProfit(int prices[], int n) {
    int minPrice=prices[0];
    int maxProfit=0;
    for (int i=1; i<n;++i)
    {
        if (prices[i]<minPrice)
        {
            minPrice=prices[i];
        }
        else if (prices[i]-minPrice > maxProfit)
        {
            maxProfit=prices[i]-minPrice;
        }
    }

    return maxProfit;
}

int main()
{
    int n;
    cout<<"Enter number of days: ";
    cin>>n;

    int prices[100];
    cout<<"Enter stock prices for "<<n<<" days:\n";
    for(int i=0;i<n;++i)
    {
        cin>>prices[i];
    }

    int profit=maxProfit(prices, n);
    cout<<"Maximum profit: "<<profit<< endl;

    return 0;
}
