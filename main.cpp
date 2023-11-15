#include <iostream>
#include <cmath>
#include <string>
#include <ctype.h>

using namespace std;

// creating a Node class to implement our equations in binary tree
class Treenode{
public:
    int data;
    Treenode *right, *left;
    // default binary tree data structure
    Treenode(int value){
        data = value;
        right = NULL;
        left = NULL;
    }
};

// Tree root
class Tree{
public:
    Treenode *root;
    Tree(){
        root = NULL;
    }
};

// binary tree printing implementation
int height(Treenode *root);
int getcol(int h);
void printTree(int **M, Treenode *root, int col, int row, int height);
void TreePrinter(Tree tree);

// Genotype Frequency calculator
double calculateGenotypeFrequency(double p, double q);
void calculateGenotypeFrequencyOption();

// Photosynthesis Equation
void photosynthesisEquation();

// Cellular respiration equation
void cellularRespirationEquation();

// Enzyme Kinetics equation/formula
double michaelisMenten(double substrateConcentration, double vmax, double km);
void enzymeKinetics();

// Nernst equation
double nernstEquation(double standartCellPotential, double temperature, int numberOfElectronsTransferred, double reactionQuontient);
void nernstEquationOption();

// Henderson hasselbalch equation
double hasselbalchEquation();
void hasselbalchEquationOption();

// DNA transcription
string dnaTranscription(string DNA);
void DNAtranscript();

int main(){
    
    int option;
    char choice;
    // creating a do-while loop to make an analogue of menu
    do{
        
        cout<<"-----Biology calculator-----\n";
        cout<<"1) Calculate genotype frequency\n";
        cout<<"2) Photosynthesis equation\n";
        cout<<"3) Cellular respiration equation\n";
        cout<<"4) Enzyme kinetics formula/solver\n";
        cout<<"5) Nernst equation calculator\n";
        cout<<"6) Henderson Hasselbalch equation\n";
        cout<<"7) DNA transcript\n";
        
        cout<<"\nChoose one of the following option: ";
        cin>>option;
        
        switch(option){
            case 1:
                calculateGenotypeFrequencyOption();
                break;
            case 2:
                photosynthesisEquation();
                break;
            case 3:
                cellularRespirationEquation();
                break;
            case 4:
                enzymeKinetics();
                break;
            case 5:
                nernstEquationOption();
                break;
            case 6:
                hasselbalchEquationOption();
                break;
            case 7:
                DNAtranscript();
                break;
            default:
                cout<<"There is no option as this.\n";
        }
        
        cout<<"Do you want to continue? (Y/n): ";
        cin>>choice;
        
        
    }while(choice == 'y' || choice == 'Y');
}

// genotype Frequency functions
double calculateGenotypeFrequency(double p, double q){
    // formula to calculate Genotype Frequency
    double genotypeFrequency = pow(p, 2) + 2 * p * q + pow(q, 2);
    return genotypeFrequency; // printing out
    
}

void calculateGenotypeFrequencyOption(){
    
    double p, q; // declaring our p and q variables
    
    cout<<"Enter Frequency of allete p: ";
    cin>>p; // input p
    
    cout<<"Enter Frequency of allete q: ";
    cin>>q; // input q 

    double genotypeFrequency = calculateGenotypeFrequency(p, q); // otherwise it calculating it and returning our solution

    if(p + q != 1){ // if sum of p and q will not be equal to 1 it returns error
        cout<<"Error: The sum of allete frequencies must be equal to 1.\n";
    }else{
        cout<<"The genotype frequency is: "<<genotypeFrequency<<endl;   
    }
}

// photosynthesis Equation function
void photosynthesisEquation(){
    // 6CO2 + 6H2O + light energy → C6H12O6 + 6O2
    int co2 = 6; // carbon dioxide
    int h2o = 6; // water 
    int lightEnergy = 1;
    int sugar = 1;
    int o2 = 6; // oxygen
    
    // following formula
    cout<<co2<<" CO2 molecules + "<<h2o<<" H2O molecules + "<<lightEnergy<<" units of Light Energy -> "<<sugar<<" C6H12O6 molecules + "<<o2<<" O2 molecules\n"<<endl;

    /*
        CO2
        / \
       H2O Light energy
       / \ / \
       O2 Sugar
    */
    // Equation in binary tree 
    
    cout<<"Binary tree view:\n";
    Tree equationNode;
    equationNode.root = new Treenode(co2);
    equationNode.root->left = new Treenode(h2o);
    equationNode.root->right = new Treenode(lightEnergy);
    equationNode.root->left->left = new Treenode(o2);
    equationNode.root->left->right = new Treenode(o2);
    equationNode.root->right->right = new Treenode(sugar);
    equationNode.root->right->left = new Treenode(sugar);
    // printing our tree
    TreePrinter(equationNode);
}

// cellular Respiration Equation function
void cellularRespirationEquation(){
    // C6H12O6 + 6O2 → 6CO2 + 6H2O (glucose + oxygen -> carbon dioxide + water)
    int glucose = 1;
    int o2 = 6;
    int co2 = 6;
    int h2o = 6;
    int atp = 1;
    
    // following formula
    cout<<glucose<<" C6H12O6 molecules + "<<o2<<" O2 molecules -> "<<co2<<" CO2 + "<<h2o<<" H2O molecules + "<<atp<<" ATP molecules\n"<<endl;
    
    /*
      C6H12O6
        / \
      6O2 6CO2 + 6H2O
    */ 
    // cellularRespirationEquation in binary tree 
    cout<<"Binary tree view:\n";
    Tree respirationEquation;
    respirationEquation.root = new Treenode(glucose);
    respirationEquation.root->left = new Treenode(o2);
    respirationEquation.root->right = new Treenode(co2);
    // printing out our tree 
    TreePrinter(respirationEquation); 
}

// enzyme kinetics
double michaelisMenten(double substrateConcentration, double vmax, double km){ return vmax * substrateConcentration / (km + substrateConcentration); } // enzyme Kinetics formula V = Vmax [S] / (Km + [S])
void enzymeKinetics(){
    
    double substrateConcentration, vmax, km; // declaring a values
    
    cout<<"Enter the value of substrate concentration: ";
    cin>>substrateConcentration; // entering our values from user-input
    
    cout<<"Enter the maximum reaction velocity value: ";
    cin>>vmax;
    
    cout<<"Enter the Michaelis-Menten constant(km): ";
    cin>>km;
    
    double reactionRate = michaelisMenten(substrateConcentration, vmax, km); // giving all values to our functions as an argument
    cout<<"Reaction rate: "<<reactionRate<<endl; // printing out the result
}

// nernst Equation function
double nernstEquation(double standartCellPotential, double temperature, int numberOfElectronsTransferred, double reactionQuontient){ // our function takes an arguments and calculates it 
    const double gasConstant = 8.314;
    const double faradayConstant = 96485;
    
    double temperatureInKelvin = temperature + 273.15; // converting our temperature to kelvin type
    double cellPotential = standartCellPotential - (gasConstant * temperatureInKelvin * log(reactionQuontient)) / (numberOfElectronsTransferred * faradayConstant);
    // E = E° - (RT/nF)ln(Q) it calculates with this fundamental formula
    return cellPotential;    
}

void nernstEquationOption(){
    double standartCellPotential, temperature, reactionQuontient; // declaring a variables 
    int numberOfElectronsTransferred;
    
    cout<<"Enter a value of standart cell potential: ";
    cin>>standartCellPotential; // entering our variables
    
    cout<<"Enter a temperature: ";
    cin>>temperature;
    
    cout<<"Enter a number of transferred electrons: ";
    cin>>numberOfElectronsTransferred;
    // giving our values to function
    double cellPotential = nernstEquation(standartCellPotential, temperature, numberOfElectronsTransferred, reactionQuontient);
    cout<<"Cell potential = "<<cellPotential<<" V"<<endl;
    // result output
}
// Henderson hasselbalch Equation function
double hasselbalchEquation(double pKa, double concentrationOfAcidForm){
    double concentrationOfBaseForm = 1.0 - concentrationOfAcidForm;
    double pH = pKa + log10(concentrationOfBaseForm / concentrationOfAcidForm);
    // pH = pKa + log10 ([A–]/[HA]) - our formula to work with
    return pH;
}

void hasselbalchEquationOption(){
    double pKa, concentrationOfAcidForm;
    
    cout<<"Enter the value of pKa: ";
    cin>>pKa;
    
    cout<<"Enter the value of concentration of acid form: ";
    cin>>concentrationOfAcidForm;
    
    double pH = hasselbalchEquation(pKa, concentrationOfAcidForm);
    cout<<"pH = "<<pH<<endl;
}

// dna transcription functions
string dnaTranscription(string DNA){
    string RNA = "";
    
    for(int i = 0; i < DNA.length(); i++){
        if(DNA[i] == 'A'){
            RNA += 'U';
        }else if(DNA[i] == 'T'){
            RNA += 'A'; 
        }else if(DNA[i] == 'C'){
            RNA += 'G';
        }else if(DNA[i] == 'G'){
            RNA += 'C';
        }
    }
    
    return RNA;
}

void DNAtranscript(){
    
    string DNA;
    cout<<"Enter DNA values: ";
    cin>>DNA;
    
    string RNA = dnaTranscription(DNA);
    cout<<"DNA: "<<DNA<<endl;
    cout<<"RNA: "<<RNA<<endl;
    
}

// binary tree output functions
int height(Treenode *root) {
    if (root == NULL)
        return 0;
    return max(height(root->left), height(root->right)) + 1;
}
 
int getcol(int h) {
    if (h == 1)
        return 1;
    return getcol(h - 1) + getcol(h - 1) + 1;
}
 
void printTree(int **M, Treenode *root, int col, int row, int height) {
    if (root == NULL)
        return;
    M[row][col] = root->data;
    printTree(M, root->left, col - pow(2, height - 2), row + 1, height - 1);
    printTree(M, root->right, col + pow(2, height - 2), row + 1, height - 1);
}
 
void TreePrinter(Tree tree) {
    int h = height(tree.root);
    int col = getcol(h);
    int **M = new int*[h];
    for (int i = 0; i < h; i++) {
        M[i] = new int[col];
    }
    printTree(M, tree.root, col / 2, 0, h);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < col; j++) {
            if (M[i][j] == 0)
                cout << " " << " ";
            else
                cout << M[i][j] << " ";
        }
        cout << endl;
    }
}

/* REFERENCES:
    1) Formulas: https://www.quora.com/What-are-some-formulas-in-biology
    2) photosynthesis Equation: https://www.geeksforgeeks.org/photosynthesis-formula/
    3) cellular Respiration Equation: https://www.toppr.com/ask/question/what-is-respiration-give-a-balanced-equation-for-aerobic-respiration/
    4) Binary tree implementation: https://www.geeksforgeeks.org/binary-tree-data-structure/
    5) Binary tree printing out: https://www.geeksforgeeks.org/print-binary-tree-2-dimensions/
    6) enzyme Kinetics formula implementation: https://en.wikibooks.org/wiki/Structural_Biochemistry/Enzyme/Michaelis_and_Menten_Equation#:~:text=The%20Michaelis%2DMenten%20equation%20arises,and%20P%20is%20the%20product.
    7) Nernst Equation: https://en.wikipedia.org/wiki/Nernst_equation
    8) Henderson Hasselbalch Equation https://byjus.com/chemistry/henderson-hasselbalch-equation/#:~:text=pH%20%3D%20pKa%20%2B%20log10%20(%5BA%E2%80%93%5D%2F%5BHA%5D)&text=An%20equation%20that%20could%20calculate,Danish%20chemist%20Karl%20Albert%20Hasselbalch.
    9) DNA to RNA: https://exercism.org/tracks/cpp/exercises/rna-transcription/solutions/44950fb8383943c6b698f0508263cc73
*/