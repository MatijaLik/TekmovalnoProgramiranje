/*
 * Problema se lotimo s požrešnim (greedy) algoritmom.
 * Naj bo N število stolpnic
 * 
 * 1. PODPROBLEM (KAKO UGOTOVIMO, KATERE STOLPNICE SO POVEZANI)
 *  
 *   Naj bo S stack. 
 *   Za vsak index i od 1 ... N:
 *      while(S ni prazen){
 *          Naj bo j element na vrhu stacka
 *          IF (stolpnica j večja od i):
 *              Zabeležimo povezavo i<->j
 *              break;
 *          ELSE
 *              Zabeležimo povezavo i<->j
 *              Odstranimo element na vrhu stacka
 *      }
 *      Dodamo i v stack
 * 
 *  Na kratko še opišimo zakaj bo tak algoritem našel vse povezane stavbe in nič več:
 *  Lahko se prepričamo, da bodo v katerem koli trenutku na stacku bile stavbe s
 *  naraščajočimi indeksi ter padajočimi višinami.
 *  Ko obravnavamo novo stolpnico, dodamo povezave s vzemi nižjimi stolpnicami, ki so
 *  na stacku, ter prvo višjo stolpnico. (Če ti sploh obstajajo).
 *  Vse manjše stavbe na stacku lahko zbrišemo, saj ne bodo povezane z nobeno 
 *  prihodnjo stolpnico. 
 * 
 * 
 * 
 * 2. PODPROBLEM (KAKO POBARVAMO STOLPNICE)
 * 
 * Pri barvanju upoštevamo naslednja načela:
 *   a). Stolpnice barvamo od leve proti desni
 *   b). Prva stolpnica dobi barvo 1
 *   c). Ko obravnavamo novo stolpnico i:
 *      i) Naj bo A množica stolpcev s katerim je i povezana.
 *      ii) Naj bo B množica stolpcev, ki so na stacku in z njimi i ni povezan.
 *      iii) Stolp i pobarvamo isto kot najnižji stolp iz B, ki nima enake barve kot 
 *          noben stolp iz A. Če tak stolp ne obstaja, pobarvamo i z najnižjo barvo,
 *          ki ni vsebovana v A.
 * 
 * 3. PRIKAZ DELOVANJA
 *      Indeksi 0 1 2 3 4 5
 *      Višine: 2 1 5 4 3 6
 *      
 *      Obravnavamo stolp 0
 *          Dodamo stolp 0 v stack S
 *          Pobarvamo stolp 0 z barvo 1
 * 
 *      Obravnavamo stolp 1
 *          Najdemo povezavo 0 <-> 1
 *          Dodamo stolp 1 v S
 *          Pobarvamo stolp 1 z barvo 2
 * 
 *      Obravnavamo stolp 2
 *          Najdemo povezavo 1 <-> 2
 *          Vzamemo stolp 1 s stacka
 *          Najdemo povezavo 0 <-> 2
 *          Vzamemo stolp 0 s stacka
 *          Pobarvamo stolp 2 z barvo 3
 * 
 *      Obravnavamo stolp 3
 *          Najdemo povezavo 2 <-> 3
 *          Dodamo stolp 3 v S
 *          Pobarvamo stolp 3 z barvo 1
 * 
 *      Obravnavamo stolp 4
 *          Najdemo povezavo 3 <-> 4
 *          Dodamo stolp 4 v S
 *          Pobarvamo stolp 4 z barvo 3
 * 
 *      Obravnavamo stolp 5
 *          Najdemo povezavo 2 <-> 5
 *          Vzamemo stolp 3 s stacka
 *          Najdemo povezavo 2 <-> 5
 *          Vzamemo stolp 4 s stacka
 *          Najdemo povezavo 2 <-> 5
 *          Vzamemo stolp 2 s stacka
 *          Dodamo stolp 5 v S
 *          Pobarvamo stolp 5 z barvo 2
 * 
 *      Tak algoritem nam zgenerira barvanje:
 *          Indeksi 0 1 2 3 4 5
 *          Višine: 2 1 5 4 3 6
 *          Barve:  1 2 3 1 3 2
 *          
 */
