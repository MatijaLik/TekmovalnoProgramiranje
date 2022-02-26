/*
 * Za reševanje tega problema uporabimo znano podatkovno
 * strukturo trie oz. prefix tree.
 * 
 * KAKO SHRANIMO NAŠ NABOR BESED V PREFIX TREE?
 * 
 * Vsako vozlišče hrani tri podatke:
 *      Prefix S, ki ustreza temu vozlišču
 *      Pointerje k vozliščem, katerih prefix S + ena črka
 *      Seznam črk, kjer je S+črka v našem naboru besed
 * 
 * Denimo, da imamo nabor besed = {brane, brat, brati, brač, kraj}.
 * 
 * Potem bo v tem drevesu obstajalo vozlišče s podatki:
 *      S -> "bra"
 *      pointerja na vozlišča s prefixi "bran" in "brat".
 *      Črki č in t.
 * 
 * Ni težko ugotoviti, da če začnemo na korenu našega drevesa
 * (vozlišče s praznum prefixom ""), lahko s sprehodom navzdol po drevesu dosežemo
 * vse beseda iz našega nabora.
 * 
 * Besedo iz nabora dodamo v prefix tree po naslednjem postopku:
 *      Začnemo v korenu drevesa.
 *      Ponavljamo:
 *          - Premaknemo se navzdol v vozlišče, ki ustreza naslednji črki
 *          naše besede. (Če vozlišče ne obstaja, ustvarimo novo).
 *          - Ko pridemo to zadnje črke v besedi, jo zapišemo
 *              na trenutno vozlišče.
 * 
 * Demonstracija prefix drevesa je na sliki 1.
 * 
 * KAKO IŠČEMO VSE BESEDE, KI USTREZAJO NEKEMU VZORCU?
 * 
 * Dobimo nek vzorec X.
 *      Začnemo v korenu drevesa.
 *      Ponavljamo:
 *          - Premaknemo se navzdol v vozlišče, ki ustreza naslednji črki
 *          našega vzorca. Če je v vzorcu *, potem zaporedoma nadaljujemo iskanje v vseh 
 *          možnih otrocih trenutnega vozlišče.
 *          - Ko pridemo do konca svojega vzorca X, izpišemo vse beseda, ki so shranjene
 *              v trentnem vozlišču (S + {črka na vozlišču, ki ustreza S})
 *          
 * Demonstracija za vzorec X = *ra* je na sliki 2.
 * 
 */
