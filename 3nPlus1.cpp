#include <iostream>
#include <vector>

using namespace std;

uint32_t fRec(uint32_t input, uint32_t counter)
{
    if (input == 1)
        return counter;
    if (input % 2 == 0)
        return fRec(input / 2, counter + 1);
    else
        return fRec(input * 3 + 1, counter + 1);
}

uint32_t f(uint32_t input)
{
    return fRec(input, 1);
}

int main()
{
    uint32_t i, j;
    vector<uint32_t> cache(1000000, 0);
    while (true)
    {
        cin >> i;
        cin >> j;

        uint32_t maxLength = 0, primero = i, ultimo = j;
        if (primero > ultimo)
        {
            uint32_t aux = primero;
            primero = ultimo;
            ultimo = aux;
        }
        for (uint32_t indice = primero; indice < ultimo; indice++)
        {
            uint32_t func;
            if (cache[indice] != 0)
                func = cache[indice];
            else
            {
                func = f(indice);
                cache[indice] = func;
            }
            if (maxLength < func)
                maxLength = func;
        }

        printf("%d %d %d\n", i, j, maxLength);
    }
}