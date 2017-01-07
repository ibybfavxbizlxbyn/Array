#ifndef ARRAY_H_INCLUDED
#define ARRAY_H_INCLUDED

#include <iostream>
#include <cstdlib>
#include <conio.h>

using namespace std;

class _array
{
private:
    unsigned int n; // Quantity of array elements
    int* arr; // Array

    /*
        File Existence Method
    */
    bool is_file (const string file_name = "array.txt") const
    {
        ifstream fin;

        if (file_name == "array.txt")
        {
            fin.open("array.txt");
        } else
        if (file_name == "array.txt")
        {
            fin.open("array.txt");
        } else
        if (file_name == "array_mult.txt")
        {
            fin.open("array_mult.txt");
        } else
        if (file_name == "N.txt")
        {
            fin.open("N.txt");
        }

        if (!fin.is_open())
        {
            cout << "Error: No such file(\"" << file_name << "\");" << endl;
            cout << "Would you like to create file \"" << file_name << "\"(y/n): ";
            char answer;
            cin >> answer;
            if (answer == 'y')
            {
                ofstream fout;
                if (file_name == "array.txt")
                {
                    fout.open("array.txt");
                } else
                if (file_name == "array2.txt")
                {
                    fout.open("array2.txt");
                } else
                if (file_name == "array_mult.txt")
                {
                    fout.open("array_mult.txt");
                } else
                if (file_name == "N.txt")
                {
                    fout.open("N.txt");
                }
                cout << "File \"" << file_name << "\" was sucessful created;" << endl;
                fout.close();
            } else
            if (answer != 'n')
            {
                cout << "Error: wrong input of data" << endl;
            }
        } else
        {
            fin.close();
            return true;
        }
        fin.close();
        return false;
    }

    /*
        File Print Method
    */
    void file_print(const string file_name = "array.txt", const int mat = 1) const
    {
        ofstream fout;
        if (file_name == "array.txt")
        {
            fout.open("array.txt");
        } else
        if (file_name == "array_mult.txt")
        {
            fout.open("array_mult.txt");
        } else
        if (file_name == "array_summ.txt")
        {
            fout.open("array_summ.txt");
        }

        for (int i = 0; i < this->n; i++)
        {
            fout << this->arr[i];
        }
        fout << "\r\n";
        fout.close();
    }

    /*
        File Read Method
    */
    void file_read (const string file_name = "array.txt")
    {
        ifstream fin;
        if (file_name == "array.txt")
        {
            fin.open("array.txt");
        } else
        if (file_name == "array2.txt")
        {
            fin.open("array2.txt");
        }

        for (int i = 0; i < this->n; i++)
        {
            fin >> this->arr[i];
        }
        fin.close();
    }

    /*
        Console Print Method
    */
    void console_print() const
    {
        for (int i = 0; i < this->n; i++)
        {
            this->arr[i];
        }
        cout << endl;
    }


    /*
        Console Read Method
    */
    void console_read ()
    {
        for (int i = 0; i < this->n; i++)
        {
            cin >> this->arr[i];
        }
    }



public:

    /*
        Constructor
    */
    _array (const int n = 0, bool from_file = false)
    {
        this->n = n;
        this->arr = new int [this->n];
        if (!from_file)
        {
            cout << "Input main array:" << endl;

        }

    }

    /*
        Destructor
    */
    ~ _array ()
    {
        cout << "\t Deleting array" << endl;
        this->console_print();

        cout << "Would you like to save array to file(\"array.txt\")(y/n): ";
        char answer;
        cin >> answer;
        if (answer == 'y')
        {
            this->is_file();
            this->file_print();
        } else
        if (answer != 'n')
        {
            cout << "Error: wrong input of data" << endl;
        }
        delete [] this->arr;
    }

    /*
        Print Method
    */
    void print (const bool in_file = false)
    {
        if (in_file == false)
        {
            cout << "Main array: " << endl;
            this->console_print();
        } else
        {
            this->is_file();
            this->file_print();
            cout << "Array was successfully writed to file(\"array.txt\");" << endl;
        }
    }

    /*
        Get Methods
    */
    int getN (bool in_file = false) const
    {
        if (in_file == true)
        {
            this->is_file("N.txt");
            this->file_print("N.txt");
        } else
        {
            return this->n;
        }
        return 0;
    }

    int* getArray () const
    {
        return this->arr;
    }

    /*
        Array multiplication Method
    */
    int* multiply_array(const bool from_file = false)
    {
        int* arr2 = new int[this->n];
        if (from_file == false)
        {
            cout << "Enter second array: " << endl;
            for (int i = 0; i < n; i++)
            {
                cin >> this->arr2[i];
            }
        } else
        {
            this->is_file("array2.txt");
            this->file_read("array2.txt");
        }

        int* arr3 = new int[this->n];

        for (int i = 0; i < this->n; i++)
        {
            arr3[i] = this->arr[i] * arr2[i];
        }

        cout << "Would you like to save array to the file(\"array_mult.txt\")(y/n): ";
        char in_file;
        cin >> in_file;
        if (in_file == 'y')
        {
            this->is_file("array_mult.txt");
            ofstream fout;
            fout.open("array_mult.txt");
            for (int i = 0; i < this->n; i++)
            {
                fout << arr3
            }
            fout << "\r\n";
            fout.close();
            cout << "Multiplication result was successfully writed to file(\"array_mult.txt\");" << endl;
        }else
        if (in_file != 'n')
        {
            cout << "Error: wrong input of data;" << endl;
        }

        if (in_file == 'y')
            return NULL;

        cout << "Multiplication result: " << endl;
        for (int i = 0; i < this->n; i++)
        {
            cout << arr3[i] << " ";
        }
        cout << endl;

        system("pause");
        return mat3;
    }

    /*
        Array addind Method
    */
    int* add_array (bool from_file = false)
    {
        int* arr2 = new int[this->n];
        if (from_file == false)
        {
            cout << "Enter second array: " << endl;
            for (int i = 0; i < n; i++)
            {
                cin >> arr2[i];
            }
        } else
        {
            this->is_file("array2.txt");
            this->file_read("array2.txt");
        }

        int* arr3 = new int[this->n*this->n];

        for (int i = 0; i < this->n; i++)
        {
            arr3[i] = this->arr[i] + arr2[i];
        }

        cout << "Would you like to save array to the file(\"add_mult.txt\")(y/n): ";
        char in_file;
        cin >> in_file;
        if (in_file == 'y')
        {
            this->is_file("add_mult.txt");
            ofstream fout;
            fout.open("add_mult.txt");
            for (int i = 0; i < this->n; i++)
            {
                for (int j = 0; j < this->n; j++)
                {
                    fout << arr3[this->n] << " ";
                }
                fout << "\r\n";
            }
            fout.close();
            cout << "Mutrix summ was successfully writed to file(\"array_mult.txt\");" << endl;
        }else
        if (in_file != 'n')
        {
            cout << "Error: wrong input of data" << endl;
        }

        if (in_file == 'y')
            return NULL;

        cout << "array summ: " << endl;
        for (int i = 0; i < this->n; i++)
        {
            cout << arr3[i];
        }
        cout << endl;

        system("pause");
        return arr3;
    }

    /*
        Array Sort Method
    */
    void sort_array()
    {
        cout << "Would you like to print sorted array to file(\"array.txt.txt\")(y/n): ";
        char answer;
        cin >> answer;

        for (int i = 0; i < this->n-1; i++)
        {
            for (int j = 0; j < this->n-1; j++)
            {
                if (this->arr[j] > this->arr[j+1])
                {
                    int temp = this->arr[j];
                    this->arr[j] = this->arr[j+1];
                    this->arr[j+1] = temp;
                }
            }
        }

        if (answer == 'y')
        {
            this->is_file();
            this->file_print();
            cout << "Sorted array was succeessfully writed to file(\"array.txt\")" << endl;
        } else
        if (answer == 'n')
        {
            this->console_print();
            system("pause");
        } else
        {
            cout << "Error: wrong input of data" << endl;
        }
    }

};

#endif // ARRAY_H_INCLUDED
