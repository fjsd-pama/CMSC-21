

#define NEEDED_BUDGET XXXXXXXXX
//assume a large budget

void labFeeIncrease(int currentFee, int currentUPBudget,
	int currentSUCsBudget, char whatWeDo[]){
	int BAYRANAN = currentFee;

	while((currentUPBudget < NEEDED_BUDGET) &&
	      (currentSUCsBudget < NEEDED_BUDGET) &&
	      (isEqual(whatWeDo, "STOP INCREASE") != true)){
	    bayranan = (currentFee * 2);
	    bayranan++;
	    printf("Magtilikadako ang bayranan! Walay hunong");
	}

	printf("No lab fee increase.");
}

bool isValid(float* fptr){
	return (*fptr * 100);
}

void main(){
    char unsaAtuBuhaton[3];

    printf("Mu-mahal na daw ang lab fees!\n");
    printf("Unsa imo buhaton? MUTABANG KA UG STOP?"\n);
    printf("Type 'YES' or 'NO': ");
    scanf("%s", &unsaAtuBuhaton);
}