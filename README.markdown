# Esempio di compito di programmazione

## Traccia

Vi è stato richiesto di scrivere un’applicazione in C che consenta la
gestione informatizzata del sistema di prenotazione di un ristorante.

Il ristorante presenta le seguenti caratteristiche:

* 5 sale (sala A, sala B, sala C, sala D e sala E; le sale A e B sono
  destinate a uso pizzeria)
* 6 giorni di apertura (su 7)
* giorni ed orari di apertura del ristorante variano in base ad un
  calendario definito mensilmente

Le prenotazioni, per semplicità, vengono gestite rispettando i seguenti
criteri:

* ogni prenotazione ha una durata di un’ora
* la prenotazione, per semplicità, può avere inizio, esclusivamente, al
  minuto 00 (alle 20:00, alle 21:00, etc)
* giorni e orari di apertura sono riportati nel file aperture.txt
* le prenotazioni sono riportate nel file prenotazioni.txt
* ciascuna prenotazione (richiesta del cliente) deve contenere giorno, ora,
  numero partecipanti, tipo_pasto (ristorante o pizzeria) e dati_contatto
  (nome, cognome, cellulare)
* Per ogni sala sono riportati il numero di tavoli, e per ogni tavolo il
  numero di posti a disposizione
* Ogni tavolo è identificato da un numero intero progressivo (1, 2, 3, …)
* Le prenotazioni si riferiscono sempre al mese corrente e non possono
  essere accettate richieste per mesi successivi

Si scriva un programma in C che soddisfi i vincoli riportati sopra.
In particolare, si definisca una struttura dati adeguata e si doti il
programma (almeno) delle seguenti funzioni:

* un menu da cui richiamare le altre funzionalità
* caricamento dei dati da file (prenotazioni.txt, aperture.txt)
* inserisci_prenotazione (funzione che consente ad un’operatore di verificare
  la disponibilità di un tavolo ed eventualmente effettuare la prenotazione)
* inserisci_prenotazioni_da_file (si supponga di avere un file che contiene
  un elenco di richieste di prenotazione -richieste.txt- da scorrere e
  trasformare in prenotazioni qualora vi siano ancora tavoli liberi)
* lista_dei_tavoli ancora disponibili (mostrati per data, fascia oraria e
  sala - es.: 04/06/2019: 21-22 - Sala A)

P.S. si consiglia di utilizzare strutture dati dinamiche

## Esecuzione

Compilare con `make` ed eseguire il binario `main`.

### Test

Per eseguire i test spostarsi nella cartella `tests`, quindi eseguire
`make`. Verranno generati i binari eseguibili da poter lanciare come test.
