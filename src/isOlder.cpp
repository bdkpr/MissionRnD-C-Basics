/*
OVERVIEW: 	Given date of births of two persons as inputs, return 1 if person one is elder,
2 if person two is elder, 0 if both are of same age.
Example: isOlder("24-07-2000", "25-07-2000") should return 1 as person one
is elder than person two.

INPUTS: 	DOBs of two persons as parameters in the format "DD-MM-YYYY".

OUTPUT: 	1 if person one is elder, 2 if person two is elder, 0 if both are of same age.

ERROR CASES: Return -1 if any DOB is invalid.

NOTES: 		Don't use any built-in C functions for comparisions. You are free to write any helper functions.
*/
int isValid(int, int, int);
void int_conversion(int *, int *, int *, char *);
int isOlder(char *dob1, char *dob2) {
	int value, date1, mt1, year1, date2, mt2, year2;
	int_conversion(&date1, &mt1, &year1, dob1);
	int_conversion(&date2, &mt2, &year2, dob2);
	if (!isValid(date1, mt1, year1))
		return -1;
	if (!isValid(date2, mt2, year2))
		return -1;
	if (year1 < year2){
		return 1;
	}
	else if (year1 > year2){
		return 2;
	}
	else if (year1 == year2){
		if (mt1 < mt2){
			return 1;
		}
		else if (mt1>mt2){
			return 2;
		}
		else if (mt1 == mt2){
			if (date1 < date2)
				return 1;
			else if (date1>date2)
				return 2;
			else if (date1 == date2)
				return 0;
		}
	}
	return 0;
}
int isValid(int date, int month, int year){
	int f = 0;
	if (month <= 7){
		if (month == 2){
			if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)){
				if (date <= 29)
					f = 1;
			}
			else{
				if (date <= 28)
					f = 1;
			}
		}
		else if (month % 2 == 0){
			if (date <= 30)
				f = 1;
		}
		else{
			if (date <= 31)
				f = 1;
		}
	}
	else if (month >= 7 && month <= 12){
		if (month % 2 == 0){
			if (date <= 31)
				f = 1;
		}
		else{
			if (date <= 30)
				f = 1;
		}
	}
	return f;
}
void int_conversion(int *date, int *month, int *year, char *dob1){
	int i, value = 0;
	for (i = 0; dob1[i] != '\0'; i++){
		if (dob1[i] == '-')
			break;
		value = value * 10 + (dob1[i] - '0');
	}
	*date = value;
	value = 0;
	for (i++; dob1[i] != '\0'; i++){
		if (dob1[i] == '-')
			break;
		value = value * 10 + (dob1[i] - '0');
	}
	*month = value;
	value = 0;
	for (i++; dob1[i] != '\0'; i++){
		if (dob1[i] == '-')
			break;
		value = value * 10 + (dob1[i] - '0');
	}
	*year = value;
}
