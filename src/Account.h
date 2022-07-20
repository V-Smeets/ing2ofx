#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <list>

namespace ing2ofx
{
    class Transaction
    {
    };

    class CheckingTransaction: public Transaction
    {
    };

    class EuroCheckingTransaction: public CheckingTransaction
    {
        int datum;
        int naamOmschrijving;
        int rekening;
        int tegenRekening;
        int code;
        int afBij;
        int bedrag;
        int mutatieSoort;
        int mededelingen;
        int saldoNaMutatie;
        int tag;
    };

    class ForeignCheckingTransaction: public CheckingTransaction
    {
        int datum;
        int naam;
        int rekening;
        int tegenRekening;
        int code;
        int afBij;
        int bedrag;
        int valuta;
        int mutatieSoort;
        int betalingskenmerk;
        int mededelingen;
        int saldoNaMutatie;
        int tag;
    };

    class SavingsTransaction: public Transaction
    {
	int datum;
	int omschrijving;
	int rekening;
	int rekeningNaam;
	int tegenrekening;
	int afBij;
	int bedrag;
	int valuta;
	int mutatiesoort;
	int mededelingen;
	int saldoNaMutatie;
    };

    class Account
    {
        std::list<Transaction> transactions;
    };

}
#endif
