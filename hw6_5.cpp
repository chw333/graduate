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
void CountBinomialFrequency(double Rn, double seg)
{
	double segment = seg;
	if (Rn >= (segment*NULL) && Rn<(segment * 1)) // k=0
	{
		aFrequencyExpDistRn[0]++;
	}
	else if (Rn >= (segment * 1) && Rn<(segment * 2)) // k=1
	{
		aFrequencyExpDistRn[1]++;
	}
	else if (Rn >= (segment * 2) && Rn<(segment * 3)) // k=2
	{
		aFrequencyExpDistRn[2]++;
	}
	else if (Rn >= (segment * 3) && Rn<(segment * 4)) // k=3
	{
		aFrequencyExpDistRn[3]++;
	}
	else if (Rn >= (segment * 4) && Rn<(segment * 5)) // k=4
	{
		aFrequencyExpDistRn[4]++;
	}
	else if (Rn >= (segment * 5) && Rn<(segment * 6)) // k=5
	{
		aFrequencyExpDistRn[5]++;
	}
	else if (Rn >= (segment * 6) && Rn<(segment * 7)) // k=6
	{
		aFrequencyExpDistRn[6]++;
	}
	else if (Rn >= (segment * 7) && Rn<(segment * 8)) // k=7
	{
		aFrequencyExpDistRn[7]++;
	}
	else if (Rn >= (segment * 8) && Rn<(segment * 9)) // k=8
	{
		aFrequencyExpDistRn[8]++;
	}
	else if (Rn >= (segment * 9) && Rn<(segment * 10))// k=9
	{
		aFrequencyExpDistRn[9]++;
	}
	else if (Rn >= (segment * 10) && Rn<(segment * 11)) // k=10
	{
		aFrequencyExpDistRn[10]++;
	}
	else if (Rn >= (segment * 11) && Rn<(segment * 12)) // k=11
	{
		aFrequencyExpDistRn[11]++;
	}
	else if (Rn >= (segment * 12) && Rn<(segment * 13)) // k=12
	{
		aFrequencyExpDistRn[12]++;
	}
	else if (Rn >= (segment * 13) && Rn<(segment * 14)) // k=13
	{
		aFrequencyExpDistRn[13]++;
	}
	else if (Rn >= (segment * 14) && Rn<(segment * 15)) // k=14
	{
		aFrequencyExpDistRn[14]++;
	}
	else if (Rn >= (segment * 15) && Rn<(segment * 16)) // k=15
	{
		aFrequencyExpDistRn[15]++;
	}
	else if (Rn >= (segment * 16) && Rn<(segment * 17)) // k=16
	{
		aFrequencyExpDistRn[16]++;
	}
	else if (Rn >= (segment * 17) && Rn<(segment * 18)) // k=17
	{
		aFrequencyExpDistRn[17]++;
	}
	else if (Rn >= (segment * 18) && Rn<(segment * 19)) // k=18
	{
		aFrequencyExpDistRn[18]++;
	}
	else if (Rn >= (segment * 19) && Rn<(segment * 20)) // k=19
	{
		aFrequencyExpDistRn[19]++;
	}
	else if (Rn = (segment * 20)) // k=20
	{
		aFrequencyExpDistRn[20]++;
	}
	else
	{
		printf("error: RN=%.5f", Rn);
	}
}
int binomialCoeff(int n, int k)
{
	// Base Cases
	if (k == 0 || k == n)
		return 1;

	// Recur
	return  binomialCoeff(n - 1, k - 1) + binomialCoeff(n - 1, k);
}
int main(void)
{
	long loopCnt;
	long geoRnCount;
	long genCount = 500000;
	long subrangeCount = 10;
	long uiFreqSum = 0;
	double GivenSRate, Denominator, Numerator, BinomialTrial;
	double Oinstant = 0, Einstant = 0, X2instant = 0, X2sum = 0;
	double Zi, Gi;
	double Sum = NULL, Total = 20.0;
	double segment = 1.0; // X2=
	printf("\n\nBINOMIAL distribution.....\n");
	memset(aFrequencyExpDistRn, NULL, 21 * sizeof(long)); // Initialize the frequency count table
	siRnCurrent = INITIAL_SEED; // 2^15 +1
	GivenSRate = 0.3;
	Denominator = GivenSRate;
	Denominator = 1 - Denominator;
	Denominator = Ln(Denominator);
	for (geoRnCount = NULL; geoRnCount<500000; geoRnCount++)
	{
		for (loopCnt = NULL; loopCnt<20; loopCnt++)
		{
			Zi = RNG_Uniform_ZeroToOne();
			if (Zi<GivenSRate)
			{
				Sum++;
			}
		}
		CountBinomialFrequency((double)Sum, segment);
		Sum = NULL;
	}
	for (loopCnt = 0; loopCnt<(subrangeCount + 1); loopCnt++)
	{
		printf("count%d=%d\n", loopCnt, aFrequencyExpDistRn[loopCnt]);
	}
	for (loopCnt = 0; loopCnt<(subrangeCount + 1); loopCnt++)
	{
		Oinstant = aFrequencyExpDistRn[loopCnt];
		Einstant = genCount*(binomialCoeff(Total, loopCnt)*pow(GivenSRate, loopCnt)*pow(1 - GivenSRate, Total - loopCnt));
		printf("Sub-Range_%d(%.1f<=k<%.1f) : O%d=%.1f, E%d=%.2f.\n",
			loopCnt, segment*loopCnt, segment*(loopCnt + 1), loopCnt, Oinstant, loopCnt, Einstant);
		X2instant = (Oinstant>Einstant) ? (((Oinstant - Einstant)*(Oinstant - Einstant)) / Einstant) : (((Einstant - Oinstant)*(Einstant - Oinstant)) / Einstant);
		printf("X2_%d = %.3f.\n", loopCnt, X2instant);
		X2sum = X2sum + X2instant;
		uiFreqSum = uiFreqSum + aFrequencyExpDistRn[loopCnt];
	}
	printf("\nTotal count = %d.\n", uiFreqSum);
	printf("Degree of freedom = %d-1 = %d.\n", subrangeCount, subrangeCount - 1);
	printf("X2 value = %.2f.\n", X2sum);
}
