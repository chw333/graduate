#include <stdio.h>
#include <stdlib.h>// refer to appendix 1
#include <memory.h>
#include <math.h>
#include <cmath>

double RNG_Uniform_ZeroToOne(void);
double Exp(double input);
double Ln(double input);
double Ceiling(double input);
int RnMax;
void CountFrequency(double Rn, double seg);
void CountPoissonFrequency(double Rn, double seg);
#define INITIAL_SEED 32769 // 215
#define MULTIPLICATIVE_FACTOR_5 65541 // 2 +1

#define MODULUS_FACTOR_2 4294967296 // 2 +5

static int aFrequencyExpDistRn[21] = { NULL };
static long long siRnCurrent = NULL;
/**
* This RNG generates a random number with uniform distribution that has the value in the range of [0,1].
* @param NONE
* @return Random Number with uniform distribution that has the value in the range of 0 and 1
*/
double RNG_Uniform_ZeroToOne(void)
{
	siRnCurrent = (MULTIPLICATIVE_FACTOR_5*siRnCurrent) % MODULUS_FACTOR_2;
	return((double)((double)siRnCurrent / (double)MODULUS_FACTOR_2));
}
double Exp(double input)
{
	return(exp(input));
}
double Ln(double input)
{
	return((double)log(input));
}
double Ceiling(double input)
{
	return(ceil(input));
}
void CountPoissonFrequency(double Rn, double seg)
{
	double segment = seg;
	if (Rn >= (segment*NULL) && Rn<=(segment * 1)) // k=0
	{
		aFrequencyExpDistRn[0]++;
	}
	else if (Rn >= (segment * 2) && Rn<=(segment * 3)) // k=1
	{
		aFrequencyExpDistRn[1]++;
	}
	else if (Rn >= (segment * 4) && Rn<=(segment * 5)) // k=2
	{
		aFrequencyExpDistRn[2]++;
	}
	else if (Rn >= (segment * 6) && Rn<=(segment * 7)) // k=3
	{
		aFrequencyExpDistRn[3]++;
	}
	else if (Rn >= (segment * 8) && Rn<=(segment * 9)) // k=4
	{
		aFrequencyExpDistRn[4]++;
	}
	else if (Rn >= (segment * 10) && Rn<=(segment * 11)) // k=5
	{
		aFrequencyExpDistRn[5]++;
	}
	else if (Rn >= (segment * 12) && Rn<=(segment * 13)) // k=6
	{
		aFrequencyExpDistRn[6]++;
	}
	else if (Rn >= (segment * 14) && Rn<=(segment * 15)) // k=7
	{
		aFrequencyExpDistRn[7]++;
	}
	else if (Rn >= (segment *16) && Rn<=(segment * 17)) // k=8
	{
		aFrequencyExpDistRn[8]++;
	}
	else if (Rn >= (segment * 18))// k=9
	{
		aFrequencyExpDistRn[9]++;
	}
	else
	{
		aFrequencyExpDistRn[20]++;
		printf("error: RN=%.5f", Rn);
	}
}

int main(void)
{
	long loopCnt;
	long possonRnCount;
	long genCount = 500000;
	long subrangeCount = 10;
	long uiFreqSum = 0;
	double Threshold, PosArrival;
	double Oinstant = 0, Einstant = 0, X2instant = 0, X2sum = 0;
	double Zi;
	double ramda = 1.0; // Given parameter Ramda = 1.
	double segment = 1.0;
	printf("POISSON distribution.....\n");
	memset(aFrequencyExpDistRn, NULL, 21 * sizeof(long)); // Initialize the frequency count table
	siRnCurrent = INITIAL_SEED; // 2^15 +1
	Threshold = 1 / Exp(1 * 6);
	PosArrival = NULL;
	Zi = RNG_Uniform_ZeroToOne();
	for (possonRnCount = NULL; possonRnCount<genCount; possonRnCount++)
	{
		while (Zi >= Threshold)
		{
			PosArrival++;
			Zi = Zi*RNG_Uniform_ZeroToOne();
		}
		CountPoissonFrequency(PosArrival, segment);
		PosArrival = NULL;
		Zi = RNG_Uniform_ZeroToOne();
	}
	for (loopCnt = 0; loopCnt<subrangeCount; loopCnt++)
	{
		printf("count%d=%d\n", loopCnt, aFrequencyExpDistRn[loopCnt]);
	}
	for (loopCnt = 0; loopCnt<(subrangeCount); loopCnt++)
	{
		Oinstant = aFrequencyExpDistRn[loopCnt];
		Einstant = genCount*(pow(1 * 6, loopCnt) / (Exp(1 * 6)*tgamma(loopCnt + 1)));
		printf("Sub-Range_%d(%.1f<= k<=%.1f) : O%d=%.1f, E%d=%.2f.\n",loopCnt, segment*loopCnt*2, segment*(loopCnt*2 + 1), loopCnt, Oinstant, loopCnt, Einstant);
		if (Oinstant > Einstant) 
		{
			X2instant = (((Oinstant - Einstant)*(Oinstant - Einstant)) / Einstant);
		}
		else
		{
			X2instant = (((Einstant - Oinstant)*(Einstant - Oinstant)) / Einstant);
		}
		printf("X2_%d = %.3f.\n", loopCnt, X2instant);
		X2sum = X2sum + X2instant;
		uiFreqSum = uiFreqSum + aFrequencyExpDistRn[loopCnt];
	}
	printf("\nTotal count = %d.\n", uiFreqSum);
	printf("Degree of freedom = %d-1 = %d.\n", subrangeCount, subrangeCount - 1);
	printf("X2 value = %.2f.\n", X2sum);
}
