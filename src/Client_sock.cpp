#include "../include/Client_sock.h"

using namespace std;

int create_socket()
{
    /*---------------------------------------------- les variables */

	/* pour le client */
	int point_acces_client;	/* le point d'accès */

	/* pour l'expédition */
	struct sockaddr_in adTCP_serveur;	/* pour mettre l'adresse de son point d'accès */



	/* divers */
	int retour;

	string str_port;
	string str_add;



	/*---------------------------------------------- l'algorithme */

	/* création d'un point d'accès */

	point_acces_client = socket (PF_INET, SOCK_STREAM, 0);
	if (point_acces_client < 0)
	{
		perror ("ERREUR-socket ");
		exit (-1);
	}

	cout << "Entrez l'adresse IP du serveur: ";
	cin >> str_add;
	cout << "\nEntrez le port : ";
	cin >> str_port;



	/* préparation de l'adresse destinataire (serveur) */

	char *cstr_add = new char [str_add.length() + 1 ];
	char *cstr_port = new char [str_port.length() + 1 ];

	strcpy (cstr_add,str_add.c_str() );
	strcpy (cstr_port,str_port.c_str() );

	cout << "IP saisie  : " << cstr_add << endl;
	cout << "PORT saisie  : " << cstr_port << endl;

	bzero (&adTCP_serveur, sizeof (adTCP_serveur));
	adTCP_serveur.sin_family = AF_INET;
	adTCP_serveur.sin_port = htons (atoi (cstr_port));
	adTCP_serveur.sin_addr.s_addr = inet_addr(cstr_add);

	delete [] cstr_add;
	delete [] cstr_port;

	/* connexion au serveur */

	retour = connect (point_acces_client,
			  (struct sockaddr *) &adTCP_serveur,
			  sizeof (adTCP_serveur));
	if (retour < 0)
	{
		cerr << " ERREUR-connect " << endl;
		exit (-1);
	}
	cout << "CONNEXION etablie" << endl;

	cout << "Please taper Enter pour commence" << endl;
	return point_acces_client;

}

string comunicate_choix(int point_acces_client, string *choixj1)
{
    /* pour l'envoi  */
	char envoyer[100];
	int emis;

	/* pour la réception  */
	char recu[100];
	int recus;

    char ch;

    while ((ch = getchar()) != EOF && ch != '\n')
    {
            ;
    }

    cout << "Choisir un personnage ? " << endl;
    scanf("%99[^\n]",envoyer);


    *choixj1 =  envoyer;

    /* envoi du bloc d'octets */
    emis = send (point_acces_client, envoyer, strlen (envoyer) + 1, 0);
    if (emis < 0)
    {
        perror ("ERREUR-send ");
        shutdown (point_acces_client, SHUT_RDWR);
        close (point_acces_client);
        exit (-1);
    }

    cout << "Vous avez choisi "<< envoyer << endl;
    cout << "..Attente de l'adversaire..." << endl ;

    /* réception de la réponse */
    recus = recv (point_acces_client, recu, sizeof (recu), 0);
    if (recus < 0)
    {
        cerr << "ERREUR-recv " << endl;
        shutdown (point_acces_client, SHUT_RDWR);
        close (point_acces_client);
        exit (-1);
    }
    return recu;
}

int attaqueAdv (int point_acces_client, int choixj1)
{

    /* pour l'envoi  */
	//char envoyer[100];

	int emis;

	/* pour la réception  */
	int recu;
	int recus;

    char ch;



    while ((ch = getchar()) != EOF && ch != '\n')
    {
            ;
    }


    /* envoi du bloc d'octets */
    emis = send (point_acces_client, &choixj1, sizeof(choixj1), 0);
    if (emis < 0)
    {
        perror ("ERREUR-send ");
        shutdown (point_acces_client, SHUT_RDWR);
        close (point_acces_client);
        exit (-1);
    }

    cout << "..Attente de l'adversaire..." << endl ;

    /* réception de la réponse */
    recus = recv (point_acces_client, &recu, sizeof (recu), 0);
    if (recus < 0)
    {
        cerr << "ERREUR-recv " << endl;
        shutdown (point_acces_client, SHUT_RDWR);
        close (point_acces_client);
        exit (-1);
    }



    return recu;
}

void fin_comm(int point_acces_client)
{
    /* fermeture du point d'accès */
	shutdown (point_acces_client, SHUT_RDWR);
	close (point_acces_client);
	cout << "FIN DE CONNEXION " << endl << endl;

}

