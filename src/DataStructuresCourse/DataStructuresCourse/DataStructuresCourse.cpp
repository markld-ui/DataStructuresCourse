#include <iostream>
#include <random>
#include <string>

using namespace std;

const int PeopleCount = 5;

struct Person
{
    string FirstName;
    string LastName;
    unsigned Age;
};

struct Product
{
    string Name;
    unsigned Cost;
    unsigned Weight;
};

void WritePerson(const Person& person)
{
    cout << "First Name: " + person.FirstName
        + "; Last Name: " + person.LastName
        + "; Age: " + to_string(person.Age)
        << endl;
}

void WriteProduct(const Product& product)
{
   cout << "Name: " + product.Name
        + "; Cost: " + to_string(product.Cost)
        + "; Weight: " + to_string(product.Weight)
        << endl;
}

Person** CreatePeopleArray()
{
    Person** people = new Person * [PeopleCount];
    people[0] = new Person();
    people[0]->FirstName = "Casey";
    people[0]->LastName = "Aguilar";
    people[0]->Age = 30;

    people[1] = new Person();
    people[1]->FirstName = "Brock";
    people[1]->LastName = "Curtis";
    people[1]->Age = 19;

    people[2] = new Person();
    people[2]->FirstName = "Blake";
    people[2]->LastName = "Diaz";
    people[2]->Age = 21;

    people[3] = new Person();
    people[3]->FirstName = "Cristian";
    people[3]->LastName = "Evans";
    people[3]->Age = 55;

    people[4] = new Person();
    people[4]->FirstName = "Les";
    people[4]->LastName = "Foss";
    people[4]->Age = 4;

    return people;

}

void ClearPerson(Person* person)
{
    delete person;
}

void ClearPeople(Person** people, int itemsCount)
{
    for (int i = 0; i < itemsCount; i++)
    {
        ClearPerson(people[i]);
    }

    delete[] people;
}


void Task1_FindPersonByLastName()
{
    cout << "Task 1 – Find Person by Last Name" << endl;
    Person** people = CreatePeopleArray();

    for (int i = 0; i < PeopleCount; i++)
    {
        WritePerson(*people[i]);
    }

    cout << endl;
    string lastName;
    cout << "Enter last name: ";
    cin >> lastName;
    int foundIndex = -1;

    // ВНИМАНИЕ: Здесь нужно реализовать логику поиска.
    for (int i = 0; i < PeopleCount; i++)
    {
        if (people[i]->LastName == lastName)
        {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex == -1)
    {
    cout << "Could not find a person by last name: " << lastName <<
        endl;
    }
    else
    {
        cout << "A person's last name "
            << lastName
            << " was found. Its index in the array is "
            << foundIndex
            << endl;
    }

    ClearPeople(people, PeopleCount);
}



//------
static void BubbleSort(double* array, int size)
{
    int temp = 0;
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

static int SearchIndex(int* array, int value, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (array[i] == value)
        {
            return i;
        }
    }
    return -1;
}

static void RemoveNoLetter(char* array, int size)
{
    for (int i = 0; i < size; i++)
    {
        if ((array[i] >= 'a') && (array[i] <= 'z') || ((array[i] >= 'A') && (array[i] <= 'Z')))
        {
            cout << array[i] << " ";
        }
    }
}

int* MakeRandomArray(int arraySize)
{
    srand(time(0));
    int* arr = new int[arraySize];

    for (int i = 0; i < arraySize; i++)
    {
        arr[i] = rand() % 100;
    }
    return arr;
}


int* ReadArray(int count)
{
    int* values = new int[count];
    for (int i = 0; i < count; i++)
    {
        cin >> values[i];
    }
    return values;
}

int CountPositiveValues(int* values, int count)
{
    int result = 0;
    for (int i = 0; i < count; i++)
    {
        if (values[i] > 0)
        {
            result++;
        }
    }
    return result;
}


// task 1

void Breakpoints()
{
    double add = 1.0;
    double sum = 0.0;
    for (int i = 0; i < 10; i++)
    {
        sum += add * i;
        add *= 1.1;
    }
    cout << "Total sum is " << sum << endl;
}


void Breakpoints2()
{
    double add = 1.0;
    double sum = 0.0;
    for (int i = 0; i < 1000; i++)
    {
        sum += add * i;
        if (i % 3 == 0)
        {
            add *= 1.1;
        }
        else
        {
            add /= 3.0;
        }
    }
    cout << "Total sum is " << sum << endl;
}

// task 2

void WorkWithFirstArray()
{
    int array[] = { 12, 21, 119, -80, 300, 75, 81, -8, 47, 31 };
    int temp = 0;
    cout << "Source array is:" << endl;

    for (int i = 0; i < 10; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;

    cout << "Sorted array is:" << endl;

    for (int i = 0; i < 10 - 1; i++)
    {
        for (int j = 0; j < 10 - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < 10; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

void WorkWithSecondArray()
{
    double array2[] = { 12.0, 21.5, 119.2, -80.7, 300.0, 75.5, 81.2, 8.1, 47.3, 31.2, 85.3, 100.1 };
    double searchingValue;
    int counter = 0;

    cout << "Enter searching value: ";
    cin >> searchingValue;

    for (int i = 0; i < 12; i++)
    {
        if (searchingValue <= array2[i])
        {
            counter++;
        }
    }

    cout << "Elements of array more than " << searchingValue << " is: " << counter << endl;
}

void WorkWithThirdArray()
{
    char arrayOfLetters[8];
    cout << "Enter array of 8 chars" << endl;
    for (int i = 0; i < 8; i++)
    {
        cout << "a[" << i << "]: ";
        cin >> arrayOfLetters[i];
    }

    cout << "Your array is:" << endl;
    for (int i = 0; i < 8; i++)
    {
        cout << arrayOfLetters[i] << " ";
    }
    cout << endl;

    cout << "All letters in your array:" << endl;

    for (int i = 0; i < 8; i++)
    {
        if ((arrayOfLetters[i] >= 'a') && (arrayOfLetters[i] <= 'z') || ((arrayOfLetters[i] >= 'A') && (arrayOfLetters[i] <= 'Z')))
        {
            cout << arrayOfLetters[i] << " ";
        }
    }
    cout << endl;
}

// task 3

double GetPower(double base, int exponent)
{
    return pow(base, exponent);
}

void DemoGetPower(double base, int exponent)
{
    cout << base << " ^ " << exponent << " = " << GetPower(base, exponent) << endl;
}

void RoundToTens(int& value)
{
    if (value % 10 < 5)
    {
        value = (value / 10) * 10;
    }
    else
    {
        value = ((value / 10) + 1) * 10;
    }
}

// task 4

void Foo(double a)
{
    cout << "Address of a in Foo(): " << &a << endl;
    cout << "Value of a in Foo(): " << a << endl;

    a = 15.0;
    cout << "New value of a in Foo(): " << a << endl;
}

void Foo2(double& a)
{
    cout << "Address of a in Foo(): " << &a << endl;
    cout << "Value of a in Foo(): " << a << endl;

    a = 15.0;
    cout << "New value of a in Foo(): " << a << endl;
}

void Foo3(double* a)
{
    cout << "Address in pointer: " << a << endl;
    cout << "Address of pointer: " << &a << endl;
    cout << "Value in pointer address: " << *a << endl;
    *a = 15.0;
    cout << "New value in pointer address: " << *a << endl;
}

// task 5

// task 6 Linear Search



int main()
{
    //task 1
    //Breakpoints();
    //Breakpoints2();

    //task 2
    //WorkWithFirstArray();
    //WorkWithSecondArray();
    //WorkWithThirdArray();

    // task 3
    //GetPower(2, 5);
    //DemoGetPower(2, 5);

    //int value = 27;
    //cout << "For " << value << " rounded value is ";
    //RoundToTens(value);
    //cout << value << endl;

    // task 4

    //code 1
    /*
    int a = 5;
    int b = 4;
    cout << "Address of a: " << &a << endl;
    cout << "Address of b: " << &b << endl;

    double c = 13.5;
    cout << "Address of c: " << &c << endl;

    bool d = true;
    cout << "Address of d: " << &d << endl;
    */

    //code 2
    /*
    int a[10] = { 1, 2, 7, -1, 5, 3, -1, 7, 1, 6 };
    cout << "size of int type: " << sizeof(int) << endl;
    
    for (int i = 0; i < 10; i++)
    {
        cout << "Address of a [" << i << "]: " << &a[i] << endl;
    }

    cout << endl;

    cout << "Size of double type : " << sizeof(double) << endl;
    double b[10] = { 1.0, 2.0, 7.0, -1.0, 5.0, 3.5, -1.8, 7.2, 1.9, 6.2 };

    for (int i = 0; i < 10; i++)
    {
        cout << "Address of b [" << i << "]: " << &b[i] << endl;
    }
    */

    // code 3
    
    /*
    int a = 5;
    int& b = a;

    cout << "Address of a: " << &a << endl;
    cout << "Address of b: " << &b << endl;
    cout << endl;
    b = 7;
    cout << "Value of a: " << a << endl;
    */

    //code 4, 5
    /*
    double a = 5.0;
    cout << "Address of a in main(): " << &a << endl;
    cout << "Value of a in main(): " << a << endl;
    cout << endl;

    //Foo(a);
    Foo2(a);

    cout << endl;
    cout << "Value of a in main(): " << a << endl;
    */

    // code 6 
    int a = 5;
    int* pointer = &a;

    cout << "Address of a: " << &a << endl;
    cout << "Address in pointer: " << pointer << endl;
    cout << "Address of pointer: " << &pointer << endl;
    cout << endl;

    *pointer = 7;
    cout << "Value in a: " << a << endl;
    cout << "Value by pointer address: " << *pointer << endl;

    // code 7
    /*
    double value = 5.0;
    double* pointer = &value;
    cout << "Address of value in main(): " << &value << endl;
    cout << "Address in pointer in main(): " << pointer << endl;
    cout << "Address of pointer in main(): " << &pointer << endl;
    cout << "Value of a in main(): " << value << endl;
    cout << endl;

    Foo3(pointer);

    cout << endl;
    cout << "Value of a in main(): " << value << endl;
    */

    // task 5

    /*
    double* array = new double[8];

    array[0] = 1.0;
    array[1] = 15.0;
    array[2] = -8.2;
    array[3] = -3.5;
    array[4] = 12.6;
    array[5] = 38.4;
    array[6] = -0.5;
    array[7] = 4.5;

    cout << "Array of double:" << endl;

    for (int i = 0; i < 8; i++) 
    {
        cout << array[i] << " ";
    }
    cout << endl;

    delete[] array;
    //---------------

    bool* array2 = new bool[8];

    array2[0] = true;
    array2[1] = false;
    array2[2] = true;
    array2[3] = true;
    array2[4] = false;
    array2[5] = true;
    array2[6] = false;
    array2[7] = false;

    cout << "Array of bool:" << endl;

    for (int i = 0; i < 8; i++) 
    {
        cout << boolalpha;
        cout << array2[i] << " ";
    }
    cout << endl;

    delete[] array2;
    //---------------

    int n;
    cout << "Enter char array size: ";
    cin >> n;
    cout << endl;

    char* array3 = new char[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Enter a[" << i << "]: ";
        cin >> array3[i];
    }
    cout << endl;

    cout << "Your char array is: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << array3[i] << " ";
    }
    cout << endl;

    delete[] array3;
    //---------------


    double* arrayB = new double[10];

    arrayB[0] = 1.0;
    arrayB[1] = 15.0;
    arrayB[2] = -8.2;
    arrayB[3] = -3.5;
    arrayB[4] = 12.6;
    arrayB[5] = 38.4;
    arrayB[6] = -0.5;
    arrayB[7] = 4.5;
    arrayB[8] = 16.7;
    arrayB[9] = 4.5;

    cout << "Array of double:" << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << arrayB[i] << " ";
    }
    cout << endl;

    BubbleSort(arrayB, 10);

    cout << "Sorted array of double:" << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << arrayB[i] << " ";
    }
    cout << endl;
    delete[] arrayB;
    //---------------
    

    int* arrayI = new int[10];

    arrayI[0] = 1;
    arrayI[1] = 15;
    arrayI[2] = -8;
    arrayI[3] = -3;
    arrayI[4] = 12;
    arrayI[5] = 38;
    arrayI[6] = 0;
    arrayI[7] = 4;
    arrayI[8] = 16;
    arrayI[9] = 4;

    cout << "Int array:" << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << arrayI[i] << " ";
    }
    cout << endl;

    int value;
    cout << "Enter searching value: ";
    cin >> value;
    cout << endl;

    cout << "Index of searchin value " << value << " is " << SearchIndex(arrayI, value, 10) << endl;

    delete[] arrayI;
    //------------
    

    char* arrayC = new char[15];

    arrayC[0] = 'a';
    arrayC[1] = '5';
    arrayC[2] = 'm';
    arrayC[3] = 'i';
    arrayC[4] = '%';
    arrayC[5] = '!';
    arrayC[6] = 's';
    arrayC[7] = 'p';
    arrayC[8] = '*';
    arrayC[9] = '9';
    arrayC[10] = 'f';
    arrayC[11] = '^';
    arrayC[12] = ';';
    arrayC[13] = 'q';
    arrayC[14] = 'k';

    cout << "Char array:" << endl;
    for (int i = 0; i < 15; i++)
    {
        cout << arrayC[i] << " ";
    }
    cout << endl;

    cout << "Letters in array:" << endl;
    RemoveNoLetter(arrayC, 15);

    delete[] arrayC;
    //-------

    int* arr5 = MakeRandomArray(5);
    int* arr8 = MakeRandomArray(8);
    int* arr13 = MakeRandomArray(13);

    cout << "Random array of 5:\n";
    for (int i = 0; i < 5; i++) {
        cout << arr5[i] << " ";
    }
    cout << "\nRandom array of 8:\n";
    for (int i = 0; i < 8; i++) {
        cout << arr8[i] << " ";
    }
    cout << "\nRandom array of 13:\n";
    for (int i = 0; i < 13; i++) {
        cout << arr13[i] << " ";
    }
    cout << endl;

    delete[] arr5;
    delete[] arr8;
    delete[] arr13;
    //-----------

    int count = 15;
    int* values = ReadArray(count);
    cout << "Count is: " << CountPositiveValues(values, count) << endl;

    delete[] values; // Нововведение. При вызове ReadArray мы не очищали память от старого массива. 
    // Внутри функции выделялась память при помощи new, поэтому, была утечка памяти.

    count = 20;
    values = ReadArray(count);
    cout << "Count is: " << CountPositiveValues(values, count) << endl;

    delete[] values;
    //--------------
    */

    // task 6 Linear Search

    Person** people = CreatePeopleArray();

    for (int i = 0; i < PeopleCount; i++)
    {
        WritePerson(*people[i]);
    }

    ClearPeople(people, PeopleCount);

}