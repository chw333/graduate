#include <stdio.h>
#include <stdlib.h>// refer to appendix 1
#include <memory.h>
#include <math.h>
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
void CountFrequency(double Rn, double seg)
{
	double segment = seg;
	if (Rn> (segment*NULL) && Rn <= (segment * 1))
	{
		aFrequencyExpDistRn[0]++;
	}
	else if (Rn> (segment * 1) && Rn <= (segment * 2)) // t: 0.5~1.0
	{
		aFrequencyExpDistRn[1]++;
	}
	else if (Rn> (segment * 2) && Rn <= (segment * 3)) // t: 1.0~1.5
	{
		aFrequencyExpDistRn[2]++;
	}
	else if (Rn> (segment * 3) && Rn <= (segment * 4)) // t: 1.5~2.0
	{
		aFrequencyExpDistRn[3]++;
	}
	else if (Rn> (segment * 4) && Rn <= (segment * 5)) // t: 2.0~2.5
	{
		aFrequencyExpDistRn[4]++;
	}
	else if (Rn> (segment * 5) && Rn <= (segment * 6)) // t: 2.5~3.0
	{
		aFrequencyExpDistRn[5]++;
	}
	else if (Rn> (segment * 6) && Rn <= (segment * 7)) // t: 3.0~3.5
	{
		aFrequencyExpDistRn[6]++;
	}
	else if (Rn> (segment * 7) && Rn <= (segment * 8)) // t: 3.5~4.0
	{
		aFrequencyExpDistRn[7]++;
	}
	else if (Rn> (segment * 8) && Rn <= (segment * 9)) // t: 4.0~4.5
	{
		aFrequencyExpDistRn[8]++;
	}
	else if (Rn> (segment * 9) && Rn <= (segment * 10))// t: 4.5~5.0
	{
		aFrequencyExpDistRn[9]++;
	}
	else if (Rn> (segment * 10) && Rn <= (segment * 11)) // t: 0~0.5
	{
		aFrequencyExpDistRn[10]++;
	}
	else if (Rn> (segment * 11) && Rn <= (segment * 12)) // t: 0.5~1.0
	{
		aFrequencyExpDistRn[11]++;
	}
	else if (Rn> (segment * 12) && Rn <= (segment * 13)) // t: 1.0~1.5
	{
		aFrequencyExpDistRn[12]++;
	}
	else if (Rn> (segment * 13) && Rn <= (segment * 14)) // t: 1.5~2.0
	{
		aFrequencyExpDistRn[13]++;
	}
	else if (Rn> (segment * 14) && Rn <= (segment * 15)) // t: 2.0~2.5
	{
		aFrequencyExpDistRn[14]++;
	}
	else if (Rn> (segment * 15) && Rn <= (segment * 16)) // t: 2.5~3.0
	{
		aFrequencyExpDistRn[15]++;
	}
	else if (Rn> (segment * 16) && Rn <= (segment * 17)) // t: 3.0~3.5
	{
		aFrequencyExpDistRn[16]++;
	}
	else if (Rn> (segment * 17) && Rn <= (segment * 18)) // t: 3.5~4.0
	{
		aFrequencyExpDistRn[17]++;
	}
	else if (Rn> (segment * 18) && Rn <= (segment * 19)) // t: 4.0~4.5
	{
		aFrequencyExpDistRn[18]++;
	}
	else if (Rn> (segment * 19) && Rn <= (segment * 20)) // t: 4.5~5.0
	{
		aFrequencyExpDistRn[19]++;
	}
	else
	{
		aFrequencyExpDistRn[20]++;
		//Printf("error: RN=%.5f", Rn);
	}
}

int main(void)
{
	long genCount = 500000;
	long subrangeCount = 10;
	long loopCnt, uiFreqSum = 0;
	double Oinstant = 0, Einstant = 0, X2instant = 0, X2sum = 0;
	double uniRn = 0, expRn = 0;
	double ramda = 1.0; // Given parameter Ramda = 1.
	double segment = 1.0;
	printf("EXPONENTIAL distribution.....\n");
	memset(aFrequencyExpDistRn, NULL, 21 * sizeof(int));
	siRnCurrent = INITIAL_SEED; // 2^15 +1
	for (loopCnt = NULL; loopCnt < genCount; loopCnt++) // 500,000
	{
		uniRn = RNG_Uniform_ZeroToOne(); /*RN with uniform distribution*/
		expRn = (-Ln(uniRn)); /*RN with exponential distribution*/
		CountFrequency(expRn, segment); /*Counting*/
	}

	for (loopCnt = 0; loopCnt < subrangeCount; loopCnt++) // 20
	{
		Oinstant = aFrequencyExpDistRn[loopCnt];
		Einstant = genCount*(Exp((-1)*(segment*loopCnt)) - Exp((-1)*(segment*(loopCnt + 1))));

		printf("Sub-Range_%d(%.1f ~%.1f) : O%d=%.1f, E%d=%.2f.", loopCnt, segment*loopCnt, segment*(loopCnt + 1), loopCnt, Oinstant, loopCnt, Einstant);

		if (Oinstant > Einstant) {
			X2instant = (((Oinstant - Einstant)*(Oinstant - Einstant)) / Einstant);
		}
		else
		{
			X2instant = (((Einstant - Oinstant)*(Einstant - Oinstant)) / Einstant);
		}

		printf("X2_%d = %.3f.\n\n", loopCnt, X2instant);

		X2sum = X2sum + X2instant;

		uiFreqSum = uiFreqSum + aFrequencyExpDistRn[loopCnt];
	}
	printf("\nTotal count = %d.\n", uiFreqSum);
	printf("X2 value = %.2f.\n", X2sum);
	printf("Degree of freedom = %d-1 = %d.\n", subrangeCount, subrangeCount - 1);
}
