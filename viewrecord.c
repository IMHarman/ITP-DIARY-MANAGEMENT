void viewrecord( )

{

    FILE *fpte ;

    system("cls");

    struct record customer ;

    char time[6],choice,filename[14];

    int ch;

    printf("\n\t\t\t\t*********************************************\n");

    printf("\t\t\t\t\t   Welcome to Viewing Menu! ");

    printf("\n\t\t\t\t*********************************************\n\n");

    choice=password();

    if(choice!=0)

    {

        return ;

    }

    do

    {

        printf("\n\t\tENTER THE DATE OF RECORD TO BE VIEWED:[yyyy-mm-dd]:");

        fflush(stdin);

        gets(filename);

        fpte = fopen ( filename, "rb" ) ;

        if ( fpte == NULL )

        {

            puts ( "\n\t\tTHE RECORD DOES NOT EXIST...\n" ) ;

            printf("\t\t\t\t\t   PRESS ANY KEY TO EXIT...");

            getch();

            return ;

        }

        system("cls");

        printf("\n\tHOW WOULD YOU LIKE TO VIEW:\n");

        printf("\n\t1.WHOLE RECORD OF THE DAY.");

        printf("\n\t2.RECORD OF FIX TIME.");

        printf("\n\tENTER YOUR CHOICE:");

        scanf("%d",&ch);

        switch(ch)

        {

        case 1:

            printf("\n\tTHE WHOLE RECORD FOR %s IS:",filename);

            while ( fread ( &customer, sizeof ( customer ), 1, fpte ) == 1 )

            {

                printf("\n");

                printf("\n\t\tTIME: %s",customer.time);

                printf("\n\t\tMEETING WITH: %s",customer.name);

                printf("\n\t\tMEETING AT: %s",customer.place);

                printf("\n\t\tDURATION: %s",customer.duration);

                printf("\n\t\tNOTE: %s",customer.note);

                printf("\n");

            }

            break;

        case 2:

            fflush(stdin);

            printf("\n\tENTER TIME:[hh:mm]:");

            gets(time);

            while ( fread ( &customer, sizeof ( customer ), 1, fpte ) == 1 )

            {

                if(strcmp(customer.time,time)==0)

                {

                    printf("\n\tYOUR RECORD IS:");

                    printf("\n\n\tTIME: %s",customer.time);

                    printf("\n\tMEETING WITH: %s",customer.name);

                    printf("\n\tMEETING AT: %s",customer.place);

                    printf("\n\tDUARATION: %s",customer.duration);

                    printf("\n\tNOTE: %s",customer.note);

                }

            }

            break;

        default:
            printf("\nYOU TYPED SOMETHING ELSE...\n");

            break;

        }

        printf("\n\n\tWOULD YOU LIKE TO CONTINUE VIEWING...(Y/N):");

        fflush(stdin);

        scanf("%c",&choice);

    }
    while(choice=='Y'||choice=='y');

    fclose ( fpte ) ;

    return ;

}