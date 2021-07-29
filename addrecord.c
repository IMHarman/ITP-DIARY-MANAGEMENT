void addrecord( )

{

    system("cls");

    FILE *fp ;

    char another = 'Y' ,time[10];

    struct record e ;

    char filename[15];

    int choice;

    printf("\t\t\t\t*********************************************\n");

    printf("\t\t\t\t\t   WELCOME TO THE ADD MENU! ");

    printf("\n\t\t\t\t*********************************************\n");

    printf("\n\n\t\t\tENTER DATE OF YOUR RECORD:[yyyy-mm-dd]:");

    fflush(stdin);

    gets(filename);

    fp = fopen (filename, "ab+" ) ;

    if ( fp == NULL )

    {

        fp=fopen(filename,"wb+");

        if(fp==NULL)

        {

            printf("\nSYSTEM ERROR...");

            printf("\nPRESS ANY KEY TO EXIT");

            getch();

            return ;

        }

    }

    while ( another == 'Y'|| another=='y' )

    {

        choice=0;

        fflush(stdin);

        printf ( "\t\t\tENTER TIME:[hh:mm]:");

        scanf("%s",time);

        rewind(fp);

        while(fread(&e,sizeof(e),1,fp)==1)

        {

            if(strcmp(e.time,time)==0)

            {

                printf("\n\t\t\tTHE RECORD ALREADY EXISTS.\n");

                choice=1;

            }

        }

        if(choice==0)

        {

            strcpy(e.time,time);

            printf("\n\t\t\tENTER NAME:");

            fflush(stdin);

            gets(e.name);

            fflush(stdin);

            printf("\t\t\tENTER PLACE:");

            gets(e.place);

            fflush(stdin);

            printf("\t\t\tENTER DURATION:");

            gets(e.duration);

            fflush(stdin);

            printf("\t\t\tNOTE:");

            gets(e.note);

            fwrite ( &e, sizeof ( e ), 1, fp ) ;

            printf("\n\t\t\tYour record is added.\n");

        }

        printf ( "\n\t\t\tDo you want to add another record?(Y/N) : " ) ;

        fflush ( stdin ) ;

        another = getchar( ) ;

    }

    fclose ( fp ) ;
	printf("\n\t\t\t\t\t******************************");
    printf("\n\n\t\t\t\t\t     PRESS ANY KEY TO EXIT.");

    getch();

}