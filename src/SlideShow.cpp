// Copyright (C) 2017 Ange Abou - Polytech'Nice
//
// Ce programme est un logiciel libre; Il peut �tre redistribu� et/ou
// modifi� sous les termes de la "GNU General Public License" (Licence
// G�n�rale Publique GNU) comme publi�s par la Free Software Foundation;
// soit la version 2, soit (au choix) toute version ult�rieure.
//
// Ce programme a une vocation �ducative, et est distribu� sans aucune
// garantie de fonctionnement; sans la garantie implicite de pouvoir 
// le commercialiser ou m�me de r�pondre � un besoin particulier.
// Se r�f�rer � la "GNU General Public License" pour plus de d�tails.
//
// Date de cr�ation: Mai 2017

#include "SlideShow.hpp"
#include <iostream>
// Pour g�n�rer des valeurs enti�res al�atoires uniform�ment r�parties
#include <random>

using namespace std;


#define CHECK_IF_INITIALISED() \
    if (!_isInitialised) { \
        cerr << "Attention: appeler d'abord init sur objet SlideShow." << endl;\
        return 0;\
    }

/* */
SlideShow::SlideShow(const char* iFilePath) 
    : _filepath(iFilePath)
    , _filestream(iFilePath)
    , _nbFilelines(0) 
    , _isInitialised(false) {
    
}

/* */
SlideShow::SlideShow(const std::string iFilePath) 
    : SlideShow(iFilePath.c_str()) {
    // Ce constructeur avec param�tre 'const string' r�utilise le constructeur
    // pr�c�dent avec param�tre 'const char*'
}
 
/* */
bool SlideShow::init() {
    /**
    *   2A)  OUTPUT prompt :
             Attention: appeler d'abord init sur objet SlideShow.
    *        Attention: appeler d'abord init sur objet SlideShow.
    *        Attention: appeler d'abord init sur objet SlideShow.
    *        ===============================================================================
    *        test cases:  3 | 1 passed | 2 failed
    *        assertions: 10 | 6 passed | 4 failed
    *
    *        Il faut au pr�alable initialier un objet SlideShow !
    *
    **/
    if (_filestream) {
        /*
        * TODO: compl�tez le code ...
        *
        * Le but est de stocker le nombre de ligne du fichier dans l'attribut '_nbFilelines'
        * et d'initialiser par cons�quent l'objet courant.
        */
        std::string line ="";
        while(getline(_filestream, line)){
            _nbFilelines += 1;
        }

    } else {
        cerr << "Erreur: impossible d'ouvrir le fichier." << endl;
        return false;
    }
    _isInitialised = true;
    
    return true;
}

const std::uint64_t SlideShow::getNumberOfSlides() {
    CHECK_IF_INITIALISED();
    
    return _nbFilelines;
}

/*
 http://fr.cppreference.com/w/cpp/numeric/random/uniform_int_distribution
 Pour produire des valeurs enti�res al�atoires uniform�ment r�parties
 */
const std::uint64_t SlideShow::getRandomNumber() {
    CHECK_IF_INITIALISED();
    
    static random_device rd;
    static mt19937 gen; // g�n�rateur
    static uniform_int_distribution<> dis(1, getNumberOfSlides());
    /*
    * TODO: Expliquez dans les commentaires 
    * 
    * - Pourquoi on utilise le mot cl� 'static' ici ? (Contrairement au code en ligne)
    *   
    *   static permet de dire de ne pas supprimer dans la variable d�s qu'on quite la fonction,
    *   par exemple lorsqu'on rappellera plus tard la fonction les variables "static"
    *   garderons leurs anciennes valeures (ressemble un peu aux variables globales)
    *
    *   
    * - Modifiez le code pour choisir les nombres al�atoires jusqu'au nombre de slides
    */
    
    return dis(gen);
}

const std::uint8_t SlideShow::displayRandomSlide(std::ostream* out) {
    std::uint8_t rc = 0; // code de retour si OK
    if (!_isInitialised) {
        cerr << "Attention: appeler d'abord init sur objet SlideShow." << endl;
        rc = 1; // code d'erreur si non initialis�
    }
    
    /*
    * TODO: compl�tez le code ...
    * 
    * Le but est d'afficher sur la sortie standard, de fa�on al�atoire,
    * le contenu d'une ligne du fichier
    * correspondant au nombre al�atoire obtenu
    */

    *out << "completez le code ... et enlevez ceci!" << endl;
    
    return rc;
}
