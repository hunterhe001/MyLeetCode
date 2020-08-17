#pragma once
enum EntryType { Legitimate, Empty, Deleted };
struct HashEntry {
	int value;
	enum EntryType Info;
};
struct HashTable {
	int TableSize;
	HashEntry* TheCells;
};


int NextPrime(int a)
{
	int i;
	while (1)
	{
		a += 1;
		for (i = 2; i <= a; i++)
		{
			if (a % i == 0)
				break;
		}
		if (i >= a)
			return a;
	}
}

HashTable* InitializeHashTable(int TableSize)
{
	HashTable* H1 = new(struct HashTable);
	H1->TheCells = new(HashEntry[NextPrime(TableSize)]);
	H1->TableSize = TableSize;
	for (int i = 0; i < TableSize; i++)
		H1->TheCells[i].Info = Empty;
	return H1;
}


int HashFunction(int Key)
{
	return Key % 11;
}


void InserTable(int Key, HashTable* H1)
{
	int loc = HashFunction(Key);
	int newloc = loc;
	int i = 1;
	while (H1->TheCells[newloc].Info != Empty)
	{
		if (i % 2 != 0)
		{
			newloc  = loc + (i + 1) / 2 * (i + 1) / 2;
			while (newloc >= H1->TableSize)
				newloc -= H1->TableSize;
		}
		else
		{
			newloc = loc +  (-1) * (i / 2) * (i / 2);
			while (newloc < 0)
				newloc += H1->TableSize;
		}
		i = i + 1;
	}
	H1->TheCells[newloc].value = Key;
	H1->TheCells[newloc].Info = Legitimate;
}