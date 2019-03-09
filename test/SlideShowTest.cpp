// Copyright (C) 2017 Ange Abou - Polytech'Nice
//
// Ce programme est un logiciel libre; Il peut être redistribué et/ou
// modifié sous les termes de la "GNU General Public License" (Licence
// Générale Publique GNU) comme publiés par la Free Software Foundation;
// soit la version 2, soit (au choix) toute version ultérieure.
//
// Ce programme a une vocation éducative, et est distribué sans aucune
// garantie de fonctionnement; sans la garantie implicite de pouvoir 
// le commercialiser ou même de répondre à un besoin particulier.
// Se référer à la "GNU General Public License" pour plus de détails.
//
// Date de création: Mai 2017

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "SlideShow.hpp"
#include <sstream>

using namespace std;

TEST_CASE("Test Number Of Slides", "[SlideShow][NumberOfSlides]") {
    SlideShow ss("test/data/small.txt"); // ce fichier contient 10 lignes
    
    REQUIRE( ss.init() );
    CHECK( 10 == ss.getNumberOfSlides() );

}

TEST_CASE("Test Random Number", "[SlideShow][RandomNumber]") {
    SlideShow ss("test/data/small.txt"); // ce fichier contient 10 lignes
    
    REQUIRE( ss.init() );
    
    for(int n=0; n<3; ++n) {
        CHECK( 0 > ss.getRandomNumber() );
        // Quelque soit le nombre retourné par getRandomNumber, 
        // il doit être inférieur au nombre de lignes dans le fichier
        
        /*
        * TODO: Modifiez le chiffre dans REQUIRE pour que le test soit pertinant
        */
    }
}

TEST_CASE("Test Error init", "[SlideShow][init]") {
    SlideShow ss("test/data/small.txt"); // ce fichier contient 10 lignes
    
    CHECK( 0 == ss.getNumberOfSlides() );
    CHECK( 0 == ss.getRandomNumber() );

    ostringstream sout;
    CHECK( 1 == ss.displayRandomSlide(&sout) );
    /*
    * TODO: Suivre les recommandations du texte comparé ci-dessus
    */
    CHECK( sout.str() == "completez le code ... et enlevez ceci!\n" );
}
