#ifndef _SIM_DEF_
#define _SIM_DEF_

typedef enum SimStatusType { arrival, start, end } SimStatus;

typedef struct SimCustomerType
{
	SimStatus status;
	int arrivalTime;	// ���� �ð�.
	int serviceTime;	// ���� �ð�.
	int startTime;		// ���� �ð�.
	int endTime;		// ���� �ð�: ���� �ð� + ���� �ð�.
} SimCustomer;

#endif