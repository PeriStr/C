
#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
typedef struct student 
{
	int id; 
	char name[50]; 
	char surname[50]; 
	int semester; 
	float grade; 
}student;
int main(int argc,char*argv[]) 
{
	int i,j,choice,pl_foithtwn,temp,key,found = 0; 
	char *epitheto; 
	struct student *stud,surname,name,semester; 
	while (choice!=8) 
	{ 
		printf("1.Initialize student list\n");
		printf("2.Add a student record\n");
		printf("3.Deleat a student record\n");
		printf("4.Display a student record by student surname\n");
		printf("5.Display students passed\n");
		printf("6.Display students failed\n");
		printf("7.Display all student records\n");
		printf("8.Exit\n");
		printf("enter your choice\n");
		scanf("%d",&choice); 
		switch(choice) 
		{
			case 1: 
				stud=(struct student*)malloc(50 * sizeof(student)); 
				if (stud == NULL)  
				{
					printf("Error! memory not allocated\n");
					return 1;
				}
				printf("Give the number of the students:\n"); 
				scanf("%d",&pl_foithtwn); 
				for (i = 0 ; i < pl_foithtwn; i++)
				{ 
				printf("*****Enter students data : \n");
				printf("Enter student id : \n");
				scanf("%d",&stud[i].id);
				printf("Enter student name : \n");
				scanf("%s",stud[i].name);
				printf("Enter student surname : \n");
				scanf("%s",stud[i].surname);
				printf("Enter student semester : \n");
				scanf("%d",&stud[i].semester);
				printf("Enter student grade : \n");
				scanf("%f",&stud[i].grade);
			    }
			    free(stud); 
			break;		
	    
	        case 2: 
				stud=(struct student*)malloc(50 * sizeof(student));
				if (stud == NULL)
				{
					printf("Error! memory not allocated\n");
					return 1;
				}
				printf("Give the number of the students:\n");
				scanf("%d",&pl_foithtwn);
				for (i = 0 ; i < pl_foithtwn; i++)
				{
				printf("*****Enter students data : \n");
				printf("Enter student id : \n");
				scanf("%d",&stud[i].id);
				printf("Enter student name : \n");
				scanf("%s",stud[i].name);
				printf("Enter student surname : \n");
				scanf("%s",stud[i].surname);
				printf("Enter student semester : \n");
				scanf("%d",&stud[i].semester);
				printf("Enter student grade : \n");
				scanf("%f",&stud[i].grade);
			    }
			    printf("insert a new student\n"); 
			    for (i=0;i<pl_foithtwn;i++) 
			    {                           
			       for(j=0;j<pl_foithtwn-i-1;j++)
			       {
			       	if(stud[j].id>stud[j+1].id) 
			       	{      
			       	 	temp = stud[j].id; 
			       	 	stud[j].id = stud[j+1].id;
			       	 	stud[j].id = temp;
					}
				   }
			    } 
			    stud=(struct student*)realloc(stud,pl_foithtwn*sizeof(student));
			    if (stud == NULL) 
				{
					printf("Error! memory not reallocated\n");
					return 1;
				}
			    printf("the id of the new student is: %d\n",stud[i]); 
			 for (i=0;i<pl_foithtwn;i++)
			 {   
			  printf("Enter the surname of the student that you want to insert: \n");
			  scanf("%s",&surname); 
			  stud[pl_foithtwn] = surname; 
			  printf("Student with the surname %s is added\n",surname,pl_foithtwn);
			  printf("Enter the name of the student that you want to insert: \n");
			  scanf("%s",&name); 
			  stud[pl_foithtwn] = name; 
			  printf("Student with the name %s is added\n",name,pl_foithtwn);
			  printf("Enter the semester of the student that you want to insert: \n");
			  scanf("%d",&semester); 
			  stud[pl_foithtwn] = semester; 
			  printf("Student that he is in the semester %d is added\n",semester,pl_foithtwn);
		     }
		     free(stud);
			break; 
			case 3: 
			stud=(struct student*)malloc(50 * sizeof(student));
				if (stud == NULL)
				{
					printf("Error! memory not allocated\n");
					return 1;
				}
				printf("Give the number of the students:\n");
				scanf("%d",&pl_foithtwn);
				for (i = 0 ; i < pl_foithtwn; i++)
				{
				printf("*****Enter students data : \n");
				printf("Enter student id : \n");
				scanf("%d",&stud[i].id);
				printf("Enter student name : \n");
				scanf("%s",stud[i].name);
				printf("Enter student surname : \n");
				scanf("%s",stud[i].surname);
				printf("Enter student semester : \n");
				scanf("%d",&stud[i].semester);
				printf("Enter student grade : \n");
				scanf("%f",&stud[i].grade);
			    }
			    stud=(struct student*)realloc(stud,pl_foithtwn*sizeof(student)); 
			    if (stud == NULL) 
				{
					printf("Error! memory not reallocated\n");
					return 1;
				}
			    printf("Enter the id of the student that you want to deleate :\n"); 
			    scanf("%d",&key); 
			    for (i=0;i<pl_foithtwn;i++) 
			    {
			    	if (stud[i].id == key) 
			    	{  
			    		found = 1;
			    		temp = stud[i].id; 
			    		stud[i].id = stud[pl_foithtwn - 1].id; 
			    		stud[pl_foithtwn - 1].id = temp;
			    		pl_foithtwn--;
					}
				}
				if (found == 0) 
				{
					printf("student with %d id not found\n",key);
				}
				else 
				{ 
					printf("student with the %d id deleated\n",key);
					printf("\n");
					for(i=0;i<pl_foithtwn;i++)
					{   
						printf("the student that deleated had code : %d \n name : %s \n surname : %s \n semester : %d \n grade : %f \n \n",stud[i].id,stud[i].name,
						stud[i].surname,stud[i].semester,stud[i].grade);	
					}
				}
				free(stud);
			break;	
			case 4: 
			stud=(struct student*)malloc(50 * sizeof(student));
				if (stud == NULL)
				{
					printf("Error! memory not allocated\n");
					return 1;
				}
				printf("Give the number of the students:\n");
				scanf("%d",&pl_foithtwn);
				for (i = 0 ; i < pl_foithtwn; i++)
				{
				printf("*****Enter students data : \n");
				printf("Enter student id : \n");
				scanf("%d",&stud[i].id);
				printf("Enter student name : \n");
				scanf("%s",stud[i].name);
				printf("Enter student surname : \n");
				scanf("%s",stud[i].surname);
				printf("Enter student semester : \n");
				scanf("%d",&stud[i].semester);
				printf("Enter student grade : \n");
				scanf("%f",&stud[i].grade);
			    }
			    printf("enter the surname of the student that you want to find\n");
			    scanf("%s",&epitheto); 
			    for(i=0;i<pl_foithtwn;i++)
			    {
			    	if (stud[i].surname == epitheto) 
			    	{
			    		found = 1;
					}
				}
				if (found == 0) 
				{
					printf("student with %s surname not found\n",epitheto);
				}
				else 
				{
					for(i=0;i<pl_foithtwn;i++) 
					{
					printf("the student that has found has code : %d \n name : %s \n surname : %s \n semester : %d \n grade : %f \n \n",stud[i].id,stud[i].name,
					stud[i].surname,stud[i].semester,stud[i].grade);	 
					}
				}
				free(stud); 
			break;
		    case 5: 
			stud=(struct student*)malloc(50 * sizeof(student));
				if (stud == NULL)
				{
					printf("Error! memory not allocated\n");
					return 1;
				}
				printf("Give the number of the students:\n");
				scanf("%d",&pl_foithtwn);
				for (i = 0 ; i < pl_foithtwn; i++)
				{
				printf("*****Enter students data : \n");
				printf("Enter student id : \n");
				scanf("%d",&stud[i].id);
				printf("Enter student name : \n");
				scanf("%s",stud[i].name);
				printf("Enter student surname : \n");
				scanf("%s",stud[i].surname);
				printf("Enter student semester : \n");
				scanf("%d",&stud[i].semester);
				printf("Enter student grade : \n");
				scanf("%f",&stud[i].grade);
			    }
			    for (i=0;i<pl_foithtwn;i++) 
			    {
			    	if (stud[i].grade >= 5) 
			    	{
			    		printf("the students that have passed the lesson is code : %d \n name : %s \n surname : %s \n semester : %d \n grade : %f \n \n",stud[i].id,stud[i].name,
						stud[i].surname,stud[i].semester,stud[i].grade);
					}
				}
				free (stud);
			break;
		    case 6: 
			stud=(struct student*)malloc(50 * sizeof(student));
				if (stud == NULL)
				{
					printf("Error! memory not allocated\n");
					return 1;
				}
				printf("Give the number of the students:\n");
				scanf("%d",&pl_foithtwn);
				for (i = 0 ; i < pl_foithtwn; i++)
				{
				printf("*****Enter students data : \n");
				printf("Enter student id : \n");
				scanf("%d",&stud[i].id);
				printf("Enter student name : \n");
				scanf("%s",stud[i].name);
				printf("Enter student surname : \n");
				scanf("%s",stud[i].surname);
				printf("Enter student semester : \n");
				scanf("%d",&stud[i].semester);
				printf("Enter student grade : \n");
				scanf("%f",&stud[i].grade);
			    }
			    for (i=0;i<pl_foithtwn;i++) 
			    {
			    	if (stud[i].grade < 5) 
			    	{
			    		printf("the students that have failed the lesson is \n code : %d \n name : %s \n surname : %s \n semester : %d \n grade : %f \n \n",stud[i].id,stud[i].name,
						stud[i].surname,stud[i].semester,stud[i].grade);
					}
				}
				free (stud); 
			break;
			case 7: 
			stud=(struct student*)malloc(50 * sizeof(student));
				if (stud == NULL)
				{
					printf("Error! memory not allocated\n");
					return 1;
				}
				printf("Give the number of the students:\n");
				scanf("%d",&pl_foithtwn);
				for (i = 0 ; i < pl_foithtwn; i++)
				{
				printf("*****Enter students data : \n");
				printf("Enter student id : \n");
				scanf("%d",&stud[i].id);
				printf("Enter student name : \n");
				scanf("%s",stud[i].name);
				printf("Enter student surname : \n");
				scanf("%s",stud[i].surname);
				printf("Enter student semester : \n");
				scanf("%d",&stud[i].semester);
				printf("Enter student grade : \n");
				scanf("%f",&stud[i].grade);
			    }
			    for (i=0;i<pl_foithtwn;i++) 
			    {       
			    		printf("code : %d \n name : %s \n surname : %s \n semester : %d \n grade : %f \n \n",stud[i].id,stud[i].name,
						stud[i].surname,stud[i].semester,stud[i].grade);
				}
				free (stud); 
			break;		
	    }
	}
return 0;	
}
