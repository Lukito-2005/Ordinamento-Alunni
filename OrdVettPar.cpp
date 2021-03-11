#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string EraseSpaceBegin(string x)
{
  int i;
  bool Fine;

  while (Fine == false)
  {
    if (i <= x.length())
    {
      if (x[i] == 32)
      {
        x.erase(x.begin() + i);
        i--;
      }
      else
      {
        Fine = true; //stop
      }
    }
    i++;
  }
  return x;
}

string EraseSpaceEnd(string x)
{
  bool Fine = false;
  int i = x.length() - 1;

  while (!Fine && i >= 0)
  {
    if (x[i] == 32)
    {
      x.erase(i);
    }
    else
    {
      Fine = true;
    }
    i--;
  }
  return x;
}

int main()
{
  int n, i;
  bool valid;

  cout << "+-----------------------------+" << endl
       << "CLASS VOTES ORGANIZER" << endl
       << "+-----------------------------+" << endl
       << endl;

  cout << "-Inserisci il numero degli alunni da registrare: ";
  cin >> n;

  string Nomi[n], Strswitch;
  int Voti[n], Intswitch;

  for (i = 0; i < n; i++)
  {
    cout << "+----------------------+" << endl;
    cout << "-Alunno N." << i + 1 << endl
         << endl;

    cout << "-Inserisci il nome: ";
    fflush(stdin);
    getline(cin, Nomi[i]);
    cout << endl << endl;
    Nomi[i] = EraseSpaceBegin(Nomi[i]);
    Nomi[i] = EraseSpaceEnd(Nomi[i]);
    transform(Nomi[i].begin(), Nomi[i].end(), Nomi[i].begin(), ::tolower);
    Voti[i] = 2;

    do
    {
      cout << "-Inserisci il voto: ";
      cin >> Voti[i];

      if (Voti[i] < 0 || Voti[i] > 10)
      {
        cout << "ERR: Inserire un numero da 1 a 10" << endl;
      }

    } while (Voti[i] < 0 || Voti[i] > 10);

    cout << endl;
    cout << "+----------------------+" << endl;

  }

  do
  {
    valid = false;
    for (i = 0; i < n - 1; i++)
    {
      if (Nomi[i] > Nomi[i + 1])
      {
        Strswitch = Nomi[i];
        Nomi[i] = Nomi[i + 1];
        Nomi[i + 1] = Strswitch;

        Intswitch = Voti[i];
        Voti[i] = Voti[i + 1];
        Voti[i + 1] = Intswitch;

        valid = true;
      }
    }
  } while (valid);

  cout << "+--------------------------+" << endl
       << "-ALUNNI ORDINATI" << endl
       << endl;

  for (i = 0; i < n; i++)
  {
    cout << "Alunno N." << i + 1 << "     Nome: " << Nomi[i] << "     Voto: " << Voti[i] << endl
         << endl;
  }

  cout << "+--------------------------+" << endl
       << "-Grazie per aver utilizzato il programma!";

  return 0;
}
