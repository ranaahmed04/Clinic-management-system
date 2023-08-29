//***************************************************************************************************************************
//-------------------------------------------Defines-------------------------------------------------------------------------
//***************************************************************************************************************************
# include<stdio.h>
#include <stdlib.h>
#include<string.h>
# include"STD_TYPES.h"
#include "BIT_MATH.h"
//***************************************************************************************************************************
//-------------------------------------------Prototypes----------------------------------------------------------------------
//***************************************************************************************************************************
void User(void);
void checkpass(void);
void options (void);
void AddPatient(void);
u8 CheckID(u32 id);
void EditInfo(void);
void CancleReservation(void);
void ReserveSlot(void);
void ShowAvaliableSlot(void);
//***************************************************************************************************************************
//-------------------------------------------Global--------------------------------------------------------------------------
//***************************************************************************************************************************
typedef struct
{
    s8 name[20];
    s8 gender[8];
    u16 age;
    u32 id;
}patient ;

typedef struct
{
    s8 from[7];
    s8 to[7];
    u8 reserved;
    s32 pid;
}timetable;

patient user[10]={{"ahmed","Male",30,2030555},{"Ali","Male",25,2030666},{"mariam","Female",30,2035577},{"salma","Female",30,2036454},{"fatma","Female",20,2535511}};
timetable reservations[15]={{"10am","10:30am",1,2030555},{"10:30am","11am",1,2030666},{"11am","12pm",1,6045014},{"12am","12:30pm",1,2535511},
{"12:30pm","1pm",1,2030666},{"2pm","2:30pm",0,0},{"2:30pm","3pm",0,0},{"3pm","3:30pm",0,0},{"3:30pm","4pm",0,0},{"4pm","4:30pm",0,0}};

//***************************************************************************************************************************
//-------------------------------------------Main Function-------------------------------------------------------------------
//***************************************************************************************************************************
void main(void)
{
	u16 u16Input = 0; 
	
	while(1){
		
		printf("Choose the suitable mode you want to login \n");
        printf(" 1- User Mode\n");
        printf(" 2- Admin Mode\n");
        scanf("%d",&u16Input);                                                                            
				
		switch (u16Input){
			
			case 1 : //user
			printf("The User Mode \n");
			User();
			break;
			
			case 2 : //admin
			printf("The Admin Mode\n");
			checkpass();
			break;
			
			default :
			printf("invalid mode\n");
			break;
		}	
	}
}
//***************************************************************************************************************************
//----------------------------------------User part--------------------------------------------------------------------------
//***************************************************************************************************************************

void User (void)
{
   
	u32 entery;
	u16 i=0,notFound=0;
	u32 searchid=0;
	printf("patient record press 1 \n");
	printf("Viewing the reservations of today press 2 \n");
	scanf("%d",&entery);
	
	// show list 
	if(entery ==1)
	{
		printf("Enter your id \n");
		scanf("%ld",&searchid);
		for(i=0;i<10;i++)
		{
			if (searchid==user[i].id)
			{
				printf("Name is : %s\n",user[i].name);
				printf("Gender is : %s\n",user[i].gender);
				printf("Age is :%d\n ",user[i].age);
				printf("ID is : %d\n",user[i].id);
				notFound=1;
			}
		}
		if(notFound==0)
			printf("There is no such a record by this Id \n");
	}
	//view reservations
	else if (entery == 2)
	{
		printf("This is the list of reservations today \n");
		 for(i=0;i<10;i++)
		{
			if(reservations[i].reserved == 1)
			{
				printf("Slot Number : %d \n",i);
				printf("From : %s \n",reservations[i].from);
				printf("To : %s \n",reservations[i].to);
				printf("Patient's ID : %ld \n",reservations[i].pid);
			}

		}
		
	}
	else
	{
		printf("Incorrect entry\n");
	}
}
//***************************************************************************************************************************
//-------------------------------------------Admin part----------------------------------------------------------------------
//***************************************************************************************************************************


//****************************check password function************************************************
void checkpass(void){
	
	 u16 pass=0,i;
	 u16 counter=1;
	 printf("Please password:\n ");
     scanf("%d",&pass);
	
	
	for(i=1;i<3;i++)
	{
	   if(pass ==1234)
		   {
			printf("Correct pasword, hello\n ");
			options();
	       }
	else{
		
		counter++;
	    printf("try again :\n");
		scanf("%d",&pass);				
    	}
		
	}
	if(counter==3)
		printf("No more trials \n ");
	}
	//****************************option function************************************************
void options(void){
	
	u16 op;
	while(1){
	printf("Choose from this list what do you want to do\n");
	printf("1-Add new patient record\n");
	printf("2-Edit patient record\n");
	printf("3-Reserve a slot with the doctor\n");
	printf("4-Cancel reservation\n");
	scanf("%d",&op);
	
	
	if(op==1){
		AddPatient();
	}
	else if(op==2){
		EditInfo();
	}
	else if(op==3){
		ReserveSlot();
	}
	else if(op==4){
		CancleReservation();
	}
	else
		printf("Invalid number!!! try again\n ");
		
	}
}
//****************************Add new patient function************************************************
void AddPatient(void){
	u8 i=0,check;
	u32 newid;
	printf("Enter patient's Id \n");
	scanf("%ld",&newid);
	
	check = CheckID(newid);
	
	if(check==0){
	for(i=0;i<10;i++){
		if(user[i].id==0)
		{
			printf("Enter patient's name \n");
			scanf("%s",&user[i].name);
			printf("Enter patient's gender \n");
			scanf("%s",&user[i].gender);
			printf("Enter patient's age \n");
			scanf("%d",&user[i].age);
			user[i].id=newid;
			break;
		}
	}
	printf("New Patient is added succesivly \n");
	}
	else{
		printf("This ID is already exisit the operation is rejected\n");
	}
}

//****************************checking Id existance function************************************************
u8 CheckID(u32 Givenid)
{
	u8 i=0;
	for(i=0;i<10;i++)
	{
		if (user[i].id== Givenid)
		{
			return 1;
			break;
		}
	}
	return 0;// we reach this when id is not found 
}

//****************************Edit in patient function************************************************

void EditInfo(void){
	
	u8 i=0,check;
	u32 newid;
	printf("Enter patient's Id \n");
	scanf("%ld",&newid);
	
	check = CheckID(newid);
	
	if(check==1){
	for(i=0;i<10;i++){
		if(user[i].id==newid)
		{
			printf("Enter patient's name after edit \n");
			scanf("%s",&user[i].name);
			printf("Enter patient's gender after edit \n");
			scanf("%s",&user[i].gender);
			printf("Enter patient's age after edit \n");
			scanf("%d",&user[i].age);
			break;
		}
	}
	printf("New Data of Patient is added succesivly \n");
	}
	else{
		printf("This ID doesnot exisit the operation is rejected\n");
	}
}

//****************************Cancle reservation function************************************************
void CancleReservation(void){
	u8 i=0,ress=0;
	u32 newid;
	
	printf("Enter patient's Id \n");
	scanf("%ld",&newid);
	
	 for(i=0;i<10;i++)
		{
			if(reservations[i].pid == newid)
			{
				reservations[i].reserved = 0;
				reservations[i].pid=0;
				printf("Reservation cancled succesivly\n");
				ress=1;
			}

		}
		if(ress!=1){
			printf("There is no reservation by this ID \n");
		}
	
}

//****************************Avaliable slots function************************************************
void ShowAvaliableSlot(void){
	u8 i=0;
	printf("This is the list of Avaliable slots today \n");
	
		 for(i=0;i<10;i++)
		{
			if(reservations[i].reserved == 0)
			{
				printf("Slot Number : %d \n",i);
				printf("From : %s \n",reservations[i].from);
				printf("To : %s \n",reservations[i].to);
			}
		}
}
//****************************Reserve slot function************************************************

void ReserveSlot(void)
{
	u8 avSlot;
	ShowAvaliableSlot();
	printf("Choose the suitable slot for you \n");
	scanf("%d",&avSlot);
	
	printf("Enter Patient's Id \n");
	scanf("%ld",&reservations[avSlot].pid);
	reservations[avSlot].reserved=1;
	
	printf("List of avaliable new slots \n");
	ShowAvaliableSlot();
		
}