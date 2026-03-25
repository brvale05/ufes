
#ifndef _DATA_H
#define _DATA_H

typedef struct Data Data;

Data* CriaData(int dia, int mes, int ano);

void LiberaData(Data* data);

void ImprimeData(Data* data);

int CalculaDiffAnos(Data *inicio, Data *fim);

Data *CopiaData(Data *d1, Data *d2);

#endif
