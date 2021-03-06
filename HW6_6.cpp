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
void CountPoissonFrequency(double Rn, double seg)
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
	else
	{
		aFrequencyExpDistRn[20]++;
		printf("error: RN=%.5f", Rn);
	}
}
void CountGeoFrequency(double Rn, double seg)
{
	double segment = seg;
	if (Rn> NULL && Rn <= (segment * 1)) // k=1
	{
		aFrequencyExpDistRn[0]++;
	}
	else if (Rn>(segment * 1) && Rn <= (segment * 2)) // k=2
	{
		aFrequencyExpDistRn[1]++;
	}
	else if (Rn> (segment * 2) && Rn <= (segment * 3)) // k=3
	{
		aFrequencyExpDistRn[2]++;
	}
	else if (Rn> (segment * 3) && Rn <= (segment * 4)) // k=4
	{
		aFrequencyExpDistRn[3]++;
	}
	else if (Rn> (segment * 4) && Rn <= (segment * 5)) // k=5
	{
		aFrequencyExpDistRn[4]++;
	}
	else if (Rn> (segment * 5) && Rn <= (segment * 6)) // k=6
	{
		aFrequencyExpDistRn[5]++;
	}
	else if (Rn> (segment * 6) && Rn <= (segment * 7)) // k=7
	{
		aFrequencyExpDistRn[6]++;
	}
	else if (Rn> (segment * 7) && Rn <= (segment * 8)) // k=8
	{
		aFrequencyExpDistRn[7]++;
	}
	else if (Rn> (segment * 8) && Rn <= (segment * 9)) // k=9
	{
		aFrequencyExpDistRn[8]++;
	}
	else if (Rn> (segment * 9) && Rn <= (segment * 10))// k=10
	{
		aFrequencyExpDistRn[9]++;
	}
	else if (Rn> (segment * 10) && Rn <= (segment * 11)) // k=11
	{
		aFrequencyExpDistRn[10]++;
	}
	else if (Rn> (segment * 11) && Rn <= (segment * 12)) // k=12
	{
		aFrequencyExpDistRn[11]++;
	}
	else if (Rn> (segment * 12) && Rn <= (segment * 13)) // k=13
	{
		aFrequencyExpDistRn[12]++;
	}
	else if (Rn> (segment * 13) && Rn <= (segment * 14)) // k=14
	{
		aFrequencyExpDistRn[13]++;
	}
	else if (Rn> (segment * 14) && Rn <= (segment * 15)) // k=15
	{
		aFrequencyExpDistRn[14]++;
	}
	else if (Rn> (segment * 15) && Rn <= (segment * 16)) // k=16
	{
		aFrequencyExpDistRn[15]++;
	}
	else if (Rn> (segment * 16) && Rn <= (segment * 17)) // k=17
	{
		aFrequencyExpDistRn[16]++;
	}
	else if (Rn> (segment * 17) && Rn <= (segment * 18)) // k=18
	{
		aFrequencyExpDistRn[17]++;
	}
	else if (Rn> (segment * 18) && Rn <= (segment * 19)) // k=19
	{
		aFrequencyExpDistRn[18]++;
	}
	else if (Rn> (segment * 19) && Rn <= (segment * 20)) // k=20
	{
		aFrequencyExpDistRn[19]++;
	}
	else
	{
		aFrequencyExpDistRn[20]++;
		printf("error: RN=%.5f", Rn);
	}
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
void CountNormalFrequency(double Rn, double seg)
{
	double segment = seg;
	double startPosition = -4;
	if (Rn >= (startPosition + segment*NULL) && Rn<(startPosition + segment * 1)) // k=0
	{
		aFrequencyExpDistRn[0]++;
	}
	else if (Rn >= (startPosition + segment * 1) && Rn<(startPosition + segment * 2)) // k=1
	{
		aFrequencyExpDistRn[1]++;
	}
	else if (Rn >= (startPosition + segment * 2) && Rn<(startPosition + segment * 3)) // k=2
	{
		aFrequencyExpDistRn[2]++;
	}
	else if (Rn >= (startPosition + segment * 3) && Rn<(startPosition + segment * 4)) // k=3
	{
		aFrequencyExpDistRn[3]++;
	}
	else if (Rn >= (startPosition + segment * 4) && Rn<(startPosition + segment * 5)) // k=4
	{
		aFrequencyExpDistRn[4]++;
	}
	else if (Rn >= (startPosition + segment * 5) && Rn<(startPosition + segment * 6)) // k=5
	{
		aFrequencyExpDistRn[5]++;
	}
	else if (Rn >= (startPosition + segment * 6) && Rn<(startPosition + segment * 7)) // k=6
	{
		aFrequencyExpDistRn[6]++;
	}
	else if (Rn >= (startPosition + segment * 7) && Rn<(startPosition + segment * 8)) // k=7
	{
		aFrequencyExpDistRn[7]++;
	}
	else if (Rn >= (startPosition + segment * 8) && Rn<(startPosition + segment * 9)) // k=8
	{
		aFrequencyExpDistRn[8]++;
	}
	else if (Rn >= (startPosition + segment * 9) && Rn<(startPosition + segment * 10)) // k=9
	{
		aFrequencyExpDistRn[9]++;
	}
	else if (Rn >= (startPosition + segment * 10) && Rn<(startPosition + segment * 11))// k=10
	{
		aFrequencyExpDistRn[10]++;
	}
	else if (Rn >= (startPosition + segment * 11) && Rn<(startPosition + segment * 12))// k=11
	{
		aFrequencyExpDistRn[11]++;
	}
	else if (Rn >= (startPosition + segment * 12) && Rn<(startPosition + segment * 13))// k=12
	{
		aFrequencyExpDistRn[12]++;
	}
	else if (Rn >= (startPosition + segment * 13) && Rn<(startPosition + segment * 14))// k=13
	{
		aFrequencyExpDistRn[13]++;
	}
	else if (Rn >= (startPosition + segment * 14) && Rn<(startPosition + segment * 15))// k=14
	{
		aFrequencyExpDistRn[14]++;
	}
	else if (Rn >= (startPosition + segment * 15) && Rn<(startPosition + segment * 16))// k=15
	{
		aFrequencyExpDistRn[15]++;
	}
	else if (Rn >= (startPosition + segment * 16) && Rn<(startPosition + segment * 17))// k=16
	{
		aFrequencyExpDistRn[16]++;
	}
	else if (Rn >= (startPosition + segment * 17) && Rn<(startPosition + segment * 18))// k=17
	{
		aFrequencyExpDistRn[17]++;
	}
	else if (Rn >= (startPosition + segment * 18) && Rn<(startPosition + segment * 19))// k=18
	{
		aFrequencyExpDistRn[18]++;
	}
	else if (Rn >= (startPosition + segment * 19) && Rn<(startPosition + segment * 20))// k=19
	{
		aFrequencyExpDistRn[19]++;
	}
	else if (Rn >= (startPosition + segment * 20) && Rn<(startPosition + segment * 21))
	{
		aFrequencyExpDistRn[20]++;
	}
	else
	{
		if (Rn == 0)
			printf("Rn=0\n");
		else
		{
			if (Rn > RnMax)
				RnMax = Rn;
		}
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
	double Oinstant = 0;
	double Z1, Z2, Z3, expX, NormTarget;
	double Compare;
	double Min = 0, Max = 1;
	double segment = 0.5; // X2=
	printf("\n\nNORMAL distribution.....\n");
	memset(aFrequencyExpDistRn, NULL, 21 * sizeof(long)); // Initialize the frequency count table
	siRnCurrent = INITIAL_SEED; // 2^15 +1
	for (geoRnCount = NULL; geoRnCount<genCount; geoRnCount++)
	{
		do
		{
			Z1 = RNG_Uniform_ZeroToOne();
			expX = -Ln(Z1);
			Z2 = RNG_Uniform_ZeroToOne();
			Compare = Exp(-0.5*pow((expX - 1), 2));
		} while (Z2 > Compare);
		Z3 = RNG_Uniform_ZeroToOne();
		if (Z3 >0.5)
			NormTarget = 1 + expX;
		else
			NormTarget = 1 - expX;
		if (NormTarget > Max)
			Max = NormTarget;
		CountNormalFrequency(NormTarget, segment);
	}
	printf("Max=%.5f\n", Max);
	for (loopCnt = 0; loopCnt<(subrangeCount); loopCnt++)
	{
		printf("count%d=%d\n", loopCnt, aFrequencyExpDistRn[loopCnt]);
	}
	for (loopCnt = 0; loopCnt<(subrangeCount); loopCnt++)
	{
		Oinstant = aFrequencyExpDistRn[loopCnt];
		printf("Sub-Range_%d(%.1f<=k<%.1f) : O%d=%.1f\n",
			loopCnt, -3.5 + segment*loopCnt, -3.5 + segment*(loopCnt + 1), loopCnt, Oinstant);
		uiFreqSum = uiFreqSum + aFrequencyExpDistRn[loopCnt];
	}
	printf("\nTotal count = %d.\n", uiFreqSum);
}
