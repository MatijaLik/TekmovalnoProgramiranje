/*
 * 
 * Vsak dogodek predstavimo kot trojico treh stevil
 * (cas, tip_dogodka, dolzina_tovornjaka)
 * kjer so:
 *   - tip_dogodka stevilo 0/1 odvisno od tega ali gre za 
 *                  prihod/odhod nekega tovornjaka
 *   - dolzina_tovornjaka je dolzina tovornjaka, ki pride
 *                         oziroma odide
 * 
 * Dogodke sortiramo po naraščajočem času.
 * Če imata dva dogodka isti čas, prej postavimo
 * odhod kot pa prihod. 
 * Če imata dva dogodka isti čas in tip_dogodka, 
 * njun relativni vrstni red ni pomemben.
 * 
 * Nato simuliramo naš urnik prihodov/odhodov tovornjakov.
 * Hranimo si spremenjlivko trenutna_dolzina, ki nam pove skupno dolžino
 * tovornjakov trenutno na parkirišču.
 * Poleg tega si hranimo spremenjlivko max_dolzina,
 * najvišjo dosedanjo vrednost trenutna_dolzina.
 * Sprehajamo se po naših sortiranih dogodkih:
 *  - če imamo tip dogodka PRIHOD, potem trenutna_dolzina pristejemo
 *                          dolzina_tovornjaka
 *  -sicer odštejemo
 * 
 * 
 * Na koncu bo zahtevana kapaciteta parkirišča enaka spremenjlivki max_dolzina
 * 
 * Rešitev deluje s časovno zahtevnostjo O(n log n) ter prostorsko zahtevnostjo O(n), kjer je n stevilo tovornjakov.
 */
