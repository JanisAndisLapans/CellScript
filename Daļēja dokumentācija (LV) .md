CellScript ir programmēšanas valoda, kas tiek izstrādāta, lai vēlāk to pielietotu spreadsheet aplikācijā

Dokumentācija šajā izstrādes posmā:

piezīmes:
Šī ir nepilnīga dokumentācija
Kompilēšana pieprasa gmp un mpfr bibliotēkas
Programma pārbaudīta tikai Ubuntu Linux vidē

1) vērtību tipi

Number - float tipa skaitlis ar neierobežotu lielumu un precizitāte, piemēram, 122, 3.14, 632557344154.12434643516 u.t.t.

String - simbolu virkne, kas atdalīta ar ' vai " zīmēm, piemēra, "TESTS", 'TESTS', ' "TESTS" '

Boolean - būla vērtība TRUE vai FALSE

InfinityType - bezgalība, kas vienmēr būs lielāka par jebkuru Number, (INF vai -INF)

NullType - tukšuma tips, NULL

Function - funkcija ar parametriem izsaucamu programmu, visas funkcijas CellScript ir anonīmas (lambdas) un var tikt piesaistītas mainīgajam,
piemēram FUNC (a, b) : RETURN a + b ENDFUNC

2) Vērtību izdrukāšana

Ar PRINT jebkuru vērtību vai izdrukāt kā simbolu virkni, piemēri

PRINT 123
PRINT "ABC"
PRINT FUNC (a, b) : RETURN a + b ENDFUNC # Rezultāts ir "FUNC"
PRINT -INF # Rezultāts ir -INF

3) Mainīgie

    Mainīgā nosaukums atbilst [A-Za-z_][A-Za-z0-9_]* 

    Deklarēšana/pieškiršana ID '=' izteiksme

    3.1) Parastiem mainīgajiem vērtība tiek piešķirta programmas izpildes laikā,
        tie ir piejami tikai šobrīdējā scope (globālajā vai funkcijā)
        lietojuma piemēri:
        a = 4
        b = 2
        b = 9
        res = a * b
        PRINT res
        # rezultāts : 36 

        a = 6
        b = a
        h = j = 2
        PRINT a + b + h + j
        # rezultāts : 16

    3.2) Konstantiem mainīgajiem var piešķirt tikai literāļu un citu konstanšu aprēķinus,
         tie tiek apreķināti jau programmas veidošanas (parsēšanas) laikā un nekad netiks rēķināti otreiz
         tos nevar mainīt un tie ir piejami šobrīdējā vai zemākā scope
         piemērs:

         CONST pi = 3.14
         CONST calc = pi * 9
         

4) IF statement

Sintakses piemēri:

IF 1 > 2:
    PRINT "Nē"
ELIF 2 == 2:
    PRINT "Jā"
ELSE:
    PRINT "Nē2"
ENDIF
#Rezultāts Jā

IF 9 < 10:
    PRINT "Jā"
ELSE : PRINT "Nē" ENDIF

    4.1) Ternārais IF var atgriezt vērtību, piemēram

        res = IF TRUE: GIVE "YES" ELSE: GIVE "NO" ENDIF
        
        un pat

        res2 = IF FALSE: GIVE "NO" ELIF TRUE: GIVE "YES" ELSE: GIVE "NO" ENDIF

        vai pat

        res3 = IF TRUE:
                GIVE 2
            ENDIF
 
5) Skaitītājcikls (FOR TO BY) skaita līdz noteiktai vērtībai (neieskaitot) ar noteiktu lēciena lielumu un izpilda programmu

piemēram

FOR i = 2 TO 10 BY 3:
    PRINT i
ENDFOR
#Rezultāts: 2
5
8

Var arī vienkāršāk (un dažādas citās kombinācijās)

FOR i TO 10:
    PRINT i
ENDFOR
#Rezultāts: 0
1
2
3
4
5
6
7
8
9

Var skaitīt arī uz otru pusi:

FOR i TO -10 BY -3:
    PRINT i
ENDFOR
#Rezultāts:  0
-3
-6
-9

Cikls var izmantot arī mainīgu vērtību izteiksmes kā parametrus:
adder = 1
FOR i TO 10 BY adder:
    PRINT i
    adder = adder + 1
ENDFOR
#Rezultāts: 0
1
3
6

    5.1) Cikla apturēšana
        BREAK - aptur šobrīdējo ciklu
        BREAK ALL - aptur "nested" ciklus, obligāti jāraksta ar vienu atstarpi starp vārdiem
        CONTINUE - paiet vienu iterāciju uz priekšu
        REPEAT - atkārto šobrīdējo iterāciju
        ADVANCE Number - paiet Number iterācijas uz priekšu (ADVANCE 0 = REPEAT, ADVANCE 1 = CONTINUE)

6) Funkcijas
    
    Visas funckijas ir lambdas

    parasti funckijas deklarē konstantas, piemēram:
    
    CONST n_fib = FUNC(n):
        IF n == 0:  
           RETURN 0
        ELIF n == 1:
           RETURN 1
        ENDIF
        RETURN n_fib(n-2) + n_fib(n-1)
    ENDFUNC

    Ja funkciju nedeklarē konstantu, tā nevar piekļū sev rekursīvi pēc mainīgā nosaukuma (vai ja tā ir literālis),
    tad var izmantot atslēgasvārdu SELF

    n_fib = FUNC(n):
        IF n == 0:  
           RETURN 0
        ELIF n == 1:
           RETURN 1
        ENDIF
        RETURN SELF(n-2) + SELF(n-1)
    ENDFUNC

    Abos gadījumus ar
    PRINT n_fib(1) #Rezultāts 1
    PRINT n_fib(4) #Rezultāts 3
    PRINT n_fib(10) #Rezultāts 55

7) STOP atslēgasvārds kalpo kā EOF, lai varētu darbināt programmu konsolē (tas eksistē tikai uz izstrādes laiku)
