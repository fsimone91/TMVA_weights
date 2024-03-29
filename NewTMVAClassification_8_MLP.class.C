// Class: ReadMLP
// Automatically generated by MethodBase::MakeClass
//

/* configuration options =====================================================

#GEN -*-*-*-*-*-*-*-*-*-*-*- general info -*-*-*-*-*-*-*-*-*-*-*-

Method         : MLP::MLP
TMVA Release   : 4.2.1         [262657]
ROOT Release   : 6.10/05       [395781]
Creator        : bjoshi
Date           : Wed Jul 24 16:39:24 2019
Host           : Linux cmsbuild24.cern.ch 2.6.32-642.11.1.el6.x86_64 #1 SMP Wed Nov 16 09:40:09 CET 2016 x86_64 x86_64 x86_64 GNU/Linux
Dir            : /afs/cern.ch/work/b/bjoshi/Analysis/workdirtmvaanalysisJul_11_2019/Code/CommonUtils/tmva
Training events: 44325
Analysis type  : [Classification]


#OPT -*-*-*-*-*-*-*-*-*-*-*-*- options -*-*-*-*-*-*-*-*-*-*-*-*-

# Set by User:
NCycles: "600" [Number of training cycles]
HiddenLayers: "N+5" [Specification of hidden layer architecture]
NeuronType: "tanh" [Neuron activation function type]
V: "False" [Verbose output (short form of "VerbosityLevel" below - overrides the latter one)]
VarTransform: "N" [List of variable transformations performed before training, e.g., "D_Background,P_Signal,G,N_AllClasses" for: "Decorrelation, PCA-transformation, Gaussianisation, Normalisation, each for the given class of events ('AllClasses' denotes all events of all classes, if no class indication is given, 'All' is assumed)"]
H: "True" [Print method-specific help message]
TestRate: "5" [Test for overtraining performed at each #th epochs]
UseRegulator: "False" [Use regulator to avoid over-training]
# Default:
RandomSeed: "1" [Random seed for initial synapse weights (0 means unique seed for each run; default value '1')]
EstimatorType: "CE" [MSE (Mean Square Estimator) for Gaussian Likelihood or CE(Cross-Entropy) for Bernoulli Likelihood]
NeuronInputType: "sum" [Neuron input function type]
VerbosityLevel: "Default" [Verbosity level]
CreateMVAPdfs: "False" [Create PDFs for classifier outputs (signal and background)]
IgnoreNegWeightsInTraining: "False" [Events with negative weights are ignored in the training (but are included for testing and performance evaluation)]
TrainingMethod: "BP" [Train with Back-Propagation (BP), BFGS Algorithm (BFGS), or Genetic Algorithm (GA - slower and worse)]
LearningRate: "2.000000e-02" [ANN learning rate parameter]
DecayRate: "1.000000e-02" [Decay rate for learning parameter]
EpochMonitoring: "False" [Provide epoch-wise monitoring plots according to TestRate (caution: causes big ROOT output file!)]
Sampling: "1.000000e+00" [Only 'Sampling' (randomly selected) events are trained each epoch]
SamplingEpoch: "1.000000e+00" [Sampling is used for the first 'SamplingEpoch' epochs, afterwards, all events are taken for training]
SamplingImportance: "1.000000e+00" [ The sampling weights of events in epochs which successful (worse estimator than before) are multiplied with SamplingImportance, else they are divided.]
SamplingTraining: "True" [The training sample is sampled]
SamplingTesting: "False" [The testing sample is sampled]
ResetStep: "50" [How often BFGS should reset history]
Tau: "3.000000e+00" [LineSearch "size step"]
BPMode: "sequential" [Back-propagation learning mode: sequential or batch]
BatchSize: "-1" [Batch size: number of events/batch, only set if in Batch Mode, -1 for BatchSize=number_of_events]
ConvergenceImprove: "1.000000e-30" [Minimum improvement which counts as improvement (<0 means automatic convergence check is turned off)]
ConvergenceTests: "-1" [Number of steps (without improvement) required for convergence (<0 means automatic convergence check is turned off)]
UpdateLimit: "10000" [Maximum times of regulator update]
CalculateErrors: "False" [Calculates inverse Hessian matrix at the end of the training to be able to calculate the uncertainties of an MVA value]
WeightRange: "1.000000e+00" [Take the events for the estimator calculations from small deviations from the desired value to large deviations only over the weight range]
##


#VAR -*-*-*-*-*-*-*-*-*-*-*-* variables *-*-*-*-*-*-*-*-*-*-*-*-

NVar 8
var_vertexKFChi2              var_vertexKFChi2              var_vertexKFChi2              Variable vertexKFChi2         units                             'F'    [0.000170780578628,99.7748565674]
var_svpvTauAngle              var_svpvTauAngle              var_svpvTauAngle              Variable svpvTauAngle         units                             'F'    [5.68933501199e-05,2.79696989059]
var_flightLenSig              var_flightLenSig              var_flightLenSig              Variable flightLenSig         units                             'F'    [0.241982340813,25.2420806885]
var_sumMuTrkKinkChi2          var_sumMuTrkKinkChi2          var_sumMuTrkKinkChi2          Variable sumMuTrkKinkChi2     units                             'F'    [4.73337364197,3176.95581055]
var_segCompMuMin              var_segCompMuMin              var_segCompMuMin              Variable segCompMuMin         units                             'F'    [0,1]
var_MinMIPLikelihood          var_MinMIPLikelihood          var_MinMIPLikelihood          Variable MinMIPLikelihood     units                             'F'    [1.02196088392e-06,0.995764613152]
var_isoMax                    var_isoMax                    var_isoMax                    Variable isoMax               units                             'F'    [0,44.1369857788]
var_maxdca                    var_maxdca                    var_maxdca                    Variable maxdca               units                             'F'    [0.000102996826172,6.07498550415]
NSpec 1
var_tauMass                   var_tauMass                   var_tauMass                   Variable tauMass              units                             'F'    [0.672131001949,3.83080458641]


============================================================================ */

#include <vector>
#include <cmath>
#include <string>
#include <iostream>

#ifndef IClassifierReader__def
#define IClassifierReader__def

class IClassifierReader {

 public:

   // constructor
   IClassifierReader() : fStatusIsClean( true ) {}
   virtual ~IClassifierReader() {}

   // return classifier response
   virtual double GetMvaValue( const std::vector<double>& inputValues ) const = 0;

   // returns classifier status
   bool IsStatusClean() const { return fStatusIsClean; }

 protected:

   bool fStatusIsClean;
};

#endif

class ReadMLP : public IClassifierReader {

 public:

   // constructor
   ReadMLP( std::vector<std::string>& theInputVars ) 
      : IClassifierReader(),
        fClassName( "ReadMLP" ),
        fNvars( 8 ),
        fIsNormalised( false )
   {      
      // the training input variables
      const char* inputVars[] = { "var_vertexKFChi2", "var_svpvTauAngle", "var_flightLenSig", "var_sumMuTrkKinkChi2", "var_segCompMuMin", "var_MinMIPLikelihood", "var_isoMax", "var_maxdca" };

      // sanity checks
      if (theInputVars.size() <= 0) {
         std::cout << "Problem in class \"" << fClassName << "\": empty input vector" << std::endl;
         fStatusIsClean = false;
      }

      if (theInputVars.size() != fNvars) {
         std::cout << "Problem in class \"" << fClassName << "\": mismatch in number of input values: "
                   << theInputVars.size() << " != " << fNvars << std::endl;
         fStatusIsClean = false;
      }

      // validate input variables
      for (size_t ivar = 0; ivar < theInputVars.size(); ivar++) {
         if (theInputVars[ivar] != inputVars[ivar]) {
            std::cout << "Problem in class \"" << fClassName << "\": mismatch in input variable names" << std::endl
                      << " for variable [" << ivar << "]: " << theInputVars[ivar].c_str() << " != " << inputVars[ivar] << std::endl;
            fStatusIsClean = false;
         }
      }

      // initialize min and max vectors (for normalisation)
      fVmin[0] = -1;
      fVmax[0] = 0.99999988079071;
      fVmin[1] = -1;
      fVmax[1] = 1;
      fVmin[2] = -1;
      fVmax[2] = 1;
      fVmin[3] = -1;
      fVmax[3] = 1;
      fVmin[4] = -1;
      fVmax[4] = 1;
      fVmin[5] = -1;
      fVmax[5] = 1;
      fVmin[6] = -1;
      fVmax[6] = 1;
      fVmin[7] = -1;
      fVmax[7] = 1;

      // initialize input variable types
      fType[0] = 'F';
      fType[1] = 'F';
      fType[2] = 'F';
      fType[3] = 'F';
      fType[4] = 'F';
      fType[5] = 'F';
      fType[6] = 'F';
      fType[7] = 'F';

      // initialize constants
      Initialize();

      // initialize transformation
      InitTransform();
   }

   // destructor
   virtual ~ReadMLP() {
      Clear(); // method-specific
   }

   // the classifier response
   // "inputValues" is a vector of input values in the same order as the 
   // variables given to the constructor
   double GetMvaValue( const std::vector<double>& inputValues ) const;

 private:

   // method-specific destructor
   void Clear();

   // input variable transformation

   double fMin_1[3][8];
   double fMax_1[3][8];
   void InitTransform_1();
   void Transform_1( std::vector<double> & iv, int sigOrBgd ) const;
   void InitTransform();
   void Transform( std::vector<double> & iv, int sigOrBgd ) const;

   // common member variables
   const char* fClassName;

   const size_t fNvars;
   size_t GetNvar()           const { return fNvars; }
   char   GetType( int ivar ) const { return fType[ivar]; }

   // normalisation of input variables
   const bool fIsNormalised;
   bool IsNormalised() const { return fIsNormalised; }
   double fVmin[8];
   double fVmax[8];
   double NormVariable( double x, double xmin, double xmax ) const {
      // normalise to output range: [-1, 1]
      return 2*(x - xmin)/(xmax - xmin) - 1.0;
   }

   // type of input variable: 'F' or 'I'
   char   fType[8];

   // initialize internal variables
   void Initialize();
   double GetMvaValue__( const std::vector<double>& inputValues ) const;

   // private members (method specific)

   double ActivationFnc(double x) const;
   double OutputActivationFnc(double x) const;

   int fLayers;
   int fLayerSize[3];
   double fWeightMatrix0to1[14][9];   // weight matrix from layer 0 to 1
   double fWeightMatrix1to2[1][14];   // weight matrix from layer 1 to 2

   double * fWeights[3];
};

inline void ReadMLP::Initialize()
{
   // build network structure
   fLayers = 3;
   fLayerSize[0] = 9; fWeights[0] = new double[9]; 
   fLayerSize[1] = 14; fWeights[1] = new double[14]; 
   fLayerSize[2] = 1; fWeights[2] = new double[1]; 
   // weight matrix from layer 0 to 1
   fWeightMatrix0to1[0][0] = 0.0854398639632888;
   fWeightMatrix0to1[1][0] = 5.13096330657529;
   fWeightMatrix0to1[2][0] = 1.15769732248401;
   fWeightMatrix0to1[3][0] = -0.159439458083446;
   fWeightMatrix0to1[4][0] = -1.60501595085133;
   fWeightMatrix0to1[5][0] = -0.817898940996837;
   fWeightMatrix0to1[6][0] = 0.619516534347069;
   fWeightMatrix0to1[7][0] = 0.134243168190391;
   fWeightMatrix0to1[8][0] = -0.217468726059027;
   fWeightMatrix0to1[9][0] = 0.532374682818344;
   fWeightMatrix0to1[10][0] = 0.0235982488435208;
   fWeightMatrix0to1[11][0] = -0.544465807146538;
   fWeightMatrix0to1[12][0] = -7.46522523882344;
   fWeightMatrix0to1[0][1] = 0.540286618780783;
   fWeightMatrix0to1[1][1] = -1.98526811615921;
   fWeightMatrix0to1[2][1] = 15.1352436600811;
   fWeightMatrix0to1[3][1] = 0.117516051470219;
   fWeightMatrix0to1[4][1] = 2.83631055684871;
   fWeightMatrix0to1[5][1] = 0.0395141888407399;
   fWeightMatrix0to1[6][1] = -3.61433766070965;
   fWeightMatrix0to1[7][1] = -17.0661627382161;
   fWeightMatrix0to1[8][1] = -24.7263004825851;
   fWeightMatrix0to1[9][1] = 0.842351649455995;
   fWeightMatrix0to1[10][1] = -10.2197088255126;
   fWeightMatrix0to1[11][1] = -2.26042089203532;
   fWeightMatrix0to1[12][1] = -1.10858097424556;
   fWeightMatrix0to1[0][2] = 0.527333346024493;
   fWeightMatrix0to1[1][2] = 0.405993998547825;
   fWeightMatrix0to1[2][2] = -6.42312163788715;
   fWeightMatrix0to1[3][2] = 0.643711302069297;
   fWeightMatrix0to1[4][2] = 1.17179364427233;
   fWeightMatrix0to1[5][2] = -0.219402041680666;
   fWeightMatrix0to1[6][2] = -7.29615494476624;
   fWeightMatrix0to1[7][2] = 0.586980599487772;
   fWeightMatrix0to1[8][2] = 0.765356609832706;
   fWeightMatrix0to1[9][2] = -2.48093070568577;
   fWeightMatrix0to1[10][2] = -0.0282231708296017;
   fWeightMatrix0to1[11][2] = 0.501557140682648;
   fWeightMatrix0to1[12][2] = 0.977296996129241;
   fWeightMatrix0to1[0][3] = 1.90272154859615;
   fWeightMatrix0to1[1][3] = -0.753791937735103;
   fWeightMatrix0to1[2][3] = 2.72866197542088;
   fWeightMatrix0to1[3][3] = 2.6621461010226;
   fWeightMatrix0to1[4][3] = -0.570645952439165;
   fWeightMatrix0to1[5][3] = 0.859911455388592;
   fWeightMatrix0to1[6][3] = -9.71914308620421;
   fWeightMatrix0to1[7][3] = 3.1541984235323;
   fWeightMatrix0to1[8][3] = -3.93969426094352;
   fWeightMatrix0to1[9][3] = 6.64593876549907;
   fWeightMatrix0to1[10][3] = 1.82501039264085;
   fWeightMatrix0to1[11][3] = 2.79378135097317;
   fWeightMatrix0to1[12][3] = 0.414951838571839;
   fWeightMatrix0to1[0][4] = -5.61399242629694;
   fWeightMatrix0to1[1][4] = -0.0709481245056615;
   fWeightMatrix0to1[2][4] = -0.233863637217418;
   fWeightMatrix0to1[3][4] = 0.140532005792145;
   fWeightMatrix0to1[4][4] = -3.14528874796183;
   fWeightMatrix0to1[5][4] = -6.96475805388349;
   fWeightMatrix0to1[6][4] = -0.368024689876554;
   fWeightMatrix0to1[7][4] = 0.0142017260550294;
   fWeightMatrix0to1[8][4] = 0.0678458263605578;
   fWeightMatrix0to1[9][4] = -0.00138390007859355;
   fWeightMatrix0to1[10][4] = -0.0189247786004545;
   fWeightMatrix0to1[11][4] = -0.481787522631813;
   fWeightMatrix0to1[12][4] = -0.197077507884379;
   fWeightMatrix0to1[0][5] = 0.199901661155902;
   fWeightMatrix0to1[1][5] = -0.003859112554262;
   fWeightMatrix0to1[2][5] = 0.157316773435827;
   fWeightMatrix0to1[3][5] = 0.39649720412789;
   fWeightMatrix0to1[4][5] = -0.120747697193944;
   fWeightMatrix0to1[5][5] = 0.110530373867281;
   fWeightMatrix0to1[6][5] = -0.0464084433241218;
   fWeightMatrix0to1[7][5] = -0.0782220082929178;
   fWeightMatrix0to1[8][5] = -0.0552550475410007;
   fWeightMatrix0to1[9][5] = -0.461267431127561;
   fWeightMatrix0to1[10][5] = -0.0568925937991171;
   fWeightMatrix0to1[11][5] = -4.28155816242882;
   fWeightMatrix0to1[12][5] = 0.1232070874712;
   fWeightMatrix0to1[0][6] = -1.25601753568371;
   fWeightMatrix0to1[1][6] = 0.166546569053137;
   fWeightMatrix0to1[2][6] = -0.660448856222456;
   fWeightMatrix0to1[3][6] = 1.51272005227434;
   fWeightMatrix0to1[4][6] = 0.111858587002465;
   fWeightMatrix0to1[5][6] = 0.996831412173668;
   fWeightMatrix0to1[6][6] = -0.0891703245458165;
   fWeightMatrix0to1[7][6] = 0.124643663486524;
   fWeightMatrix0to1[8][6] = 0.0742928635935188;
   fWeightMatrix0to1[9][6] = -0.102129107377591;
   fWeightMatrix0to1[10][6] = -10.2357225666796;
   fWeightMatrix0to1[11][6] = 0.19115366123977;
   fWeightMatrix0to1[12][6] = -0.317484760434356;
   fWeightMatrix0to1[0][7] = 0.295051515570167;
   fWeightMatrix0to1[1][7] = -1.50918330325776;
   fWeightMatrix0to1[2][7] = 1.286567238002;
   fWeightMatrix0to1[3][7] = -0.557924302805489;
   fWeightMatrix0to1[4][7] = 1.12027488656573;
   fWeightMatrix0to1[5][7] = -1.6065738524712;
   fWeightMatrix0to1[6][7] = -1.9601631554306;
   fWeightMatrix0to1[7][7] = -0.0115860390772318;
   fWeightMatrix0to1[8][7] = 1.20612892356946;
   fWeightMatrix0to1[9][7] = 0.998815178746681;
   fWeightMatrix0to1[10][7] = 0.199344077873744;
   fWeightMatrix0to1[11][7] = -0.084548147424286;
   fWeightMatrix0to1[12][7] = 0.0874038777641387;
   fWeightMatrix0to1[0][8] = 1.66928085066975;
   fWeightMatrix0to1[1][8] = -1.49856102151399;
   fWeightMatrix0to1[2][8] = 14.8425316589753;
   fWeightMatrix0to1[3][8] = -0.112806583784981;
   fWeightMatrix0to1[4][8] = 0.0766548986689767;
   fWeightMatrix0to1[5][8] = 4.68441143065672;
   fWeightMatrix0to1[6][8] = -19.3267591112722;
   fWeightMatrix0to1[7][8] = -14.3624610738703;
   fWeightMatrix0to1[8][8] = -27.545467877541;
   fWeightMatrix0to1[9][8] = 6.92959390976411;
   fWeightMatrix0to1[10][8] = -18.8193423178006;
   fWeightMatrix0to1[11][8] = 5.21856706970641;
   fWeightMatrix0to1[12][8] = -7.28987197210941;
   // weight matrix from layer 1 to 2
   fWeightMatrix1to2[0][0] = -0.525124256939585;
   fWeightMatrix1to2[0][1] = 0.879531007393272;
   fWeightMatrix1to2[0][2] = -1.15013497901128;
   fWeightMatrix1to2[0][3] = -5.81411567844362;
   fWeightMatrix1to2[0][4] = -1.30422313681043;
   fWeightMatrix1to2[0][5] = -0.623273370280176;
   fWeightMatrix1to2[0][6] = 2.27096032020013;
   fWeightMatrix1to2[0][7] = 3.57377113979902;
   fWeightMatrix1to2[0][8] = 5.71006066934159;
   fWeightMatrix1to2[0][9] = -1.95991437670272;
   fWeightMatrix1to2[0][10] = 2.26538271622107;
   fWeightMatrix1to2[0][11] = -0.781330720063276;
   fWeightMatrix1to2[0][12] = 1.16590470605011;
   fWeightMatrix1to2[0][13] = 4.73678237933136;
}

inline double ReadMLP::GetMvaValue__( const std::vector<double>& inputValues ) const
{
   if (inputValues.size() != (unsigned int)fLayerSize[0]-1) {
      std::cout << "Input vector needs to be of size " << fLayerSize[0]-1 << std::endl;
      return 0;
   }

   for (int l=0; l<fLayers; l++)
      for (int i=0; i<fLayerSize[l]; i++) fWeights[l][i]=0;

   for (int l=0; l<fLayers-1; l++)
      fWeights[l][fLayerSize[l]-1]=1;

   for (int i=0; i<fLayerSize[0]-1; i++)
      fWeights[0][i]=inputValues[i];

   // layer 0 to 1
   for (int o=0; o<fLayerSize[1]-1; o++) {
      for (int i=0; i<fLayerSize[0]; i++) {
         double inputVal = fWeightMatrix0to1[o][i] * fWeights[0][i];
         fWeights[1][o] += inputVal;
      }
      fWeights[1][o] = ActivationFnc(fWeights[1][o]);
   }
   // layer 1 to 2
   for (int o=0; o<fLayerSize[2]; o++) {
      for (int i=0; i<fLayerSize[1]; i++) {
         double inputVal = fWeightMatrix1to2[o][i] * fWeights[1][i];
         fWeights[2][o] += inputVal;
      }
      fWeights[2][o] = OutputActivationFnc(fWeights[2][o]);
   }

   return fWeights[2][0];
}

double ReadMLP::ActivationFnc(double x) const {
   // hyperbolic tan
   return tanh(x);
}
double ReadMLP::OutputActivationFnc(double x) const {
   // sigmoid
   return 1.0/(1.0+exp(-x));
}
   
// Clean up
inline void ReadMLP::Clear() 
{
   // clean up the arrays
   for (int lIdx = 0; lIdx < 3; lIdx++) {
      delete[] fWeights[lIdx];
   }
}
   inline double ReadMLP::GetMvaValue( const std::vector<double>& inputValues ) const
   {
      // classifier response value
      double retval = 0;

      // classifier response, sanity check first
      if (!IsStatusClean()) {
         std::cout << "Problem in class \"" << fClassName << "\": cannot return classifier response"
                   << " because status is dirty" << std::endl;
         retval = 0;
      }
      else {
         if (IsNormalised()) {
            // normalise variables
            std::vector<double> iV;
            iV.reserve(inputValues.size());
            int ivar = 0;
            for (std::vector<double>::const_iterator varIt = inputValues.begin();
                 varIt != inputValues.end(); varIt++, ivar++) {
               iV.push_back(NormVariable( *varIt, fVmin[ivar], fVmax[ivar] ));
            }
            Transform( iV, -1 );
            retval = GetMvaValue__( iV );
         }
         else {
            std::vector<double> iV;
            int ivar = 0;
            for (std::vector<double>::const_iterator varIt = inputValues.begin();
                 varIt != inputValues.end(); varIt++, ivar++) {
               iV.push_back(*varIt);
            }
            Transform( iV, -1 );
            retval = GetMvaValue__( iV );
         }
      }

      return retval;
   }

//_______________________________________________________________________
inline void ReadMLP::InitTransform_1()
{
   // Normalization transformation, initialisation
   fMin_1[0][0] = 0.000170780578628;
   fMax_1[0][0] = 98.0028686523;
   fMin_1[1][0] = 0.0213494841009;
   fMax_1[1][0] = 99.7748565674;
   fMin_1[2][0] = 0.000170780578628;
   fMax_1[2][0] = 99.7748565674;
   fMin_1[0][1] = 5.68933501199e-05;
   fMax_1[0][1] = 1.02695572376;
   fMin_1[1][1] = 0.000353074865416;
   fMax_1[1][1] = 2.79696989059;
   fMin_1[2][1] = 5.68933501199e-05;
   fMax_1[2][1] = 2.79696989059;
   fMin_1[0][2] = 0.297363936901;
   fMax_1[0][2] = 22.4689235687;
   fMin_1[1][2] = 0.241982340813;
   fMax_1[1][2] = 25.2420806885;
   fMin_1[2][2] = 0.241982340813;
   fMax_1[2][2] = 25.2420806885;
   fMin_1[0][3] = 5.59860038757;
   fMax_1[0][3] = 1141.87963867;
   fMin_1[1][3] = 4.73337364197;
   fMax_1[1][3] = 3176.95581055;
   fMin_1[2][3] = 4.73337364197;
   fMax_1[2][3] = 3176.95581055;
   fMin_1[0][4] = 0;
   fMax_1[0][4] = 1;
   fMin_1[1][4] = 0;
   fMax_1[1][4] = 1;
   fMin_1[2][4] = 0;
   fMax_1[2][4] = 1;
   fMin_1[0][5] = 1.02196088392e-06;
   fMax_1[0][5] = 0.995764613152;
   fMin_1[1][5] = 1.1731815448e-06;
   fMax_1[1][5] = 0.99111521244;
   fMin_1[2][5] = 1.02196088392e-06;
   fMax_1[2][5] = 0.995764613152;
   fMin_1[0][6] = 0;
   fMax_1[0][6] = 44.1369857788;
   fMin_1[1][6] = 0.0192772168666;
   fMax_1[1][6] = 41.3797569275;
   fMin_1[2][6] = 0;
   fMax_1[2][6] = 44.1369857788;
   fMin_1[0][7] = 0.000102996826172;
   fMax_1[0][7] = 6.07498550415;
   fMin_1[1][7] = 0.000661849975586;
   fMax_1[1][7] = 4.68758583069;
   fMin_1[2][7] = 0.000102996826172;
   fMax_1[2][7] = 6.07498550415;
}

//_______________________________________________________________________
inline void ReadMLP::Transform_1( std::vector<double>& iv, int cls) const
{
   // Normalization transformation
   if (cls < 0 || cls > 2) {
   if (2 > 1 ) cls = 2;
      else cls = 2;
   }
   const int nVar = 8;

   // get indices of used variables

   // define the indices of the variables which are transformed by this transformation
   static std::vector<int> indicesGet;
   static std::vector<int> indicesPut;

   if ( indicesGet.empty() ) { 
      indicesGet.reserve(fNvars);
      indicesGet.push_back( 0);
      indicesGet.push_back( 1);
      indicesGet.push_back( 2);
      indicesGet.push_back( 3);
      indicesGet.push_back( 4);
      indicesGet.push_back( 5);
      indicesGet.push_back( 6);
      indicesGet.push_back( 7);
   } 
   if ( indicesPut.empty() ) { 
      indicesPut.reserve(fNvars);
      indicesPut.push_back( 0);
      indicesPut.push_back( 1);
      indicesPut.push_back( 2);
      indicesPut.push_back( 3);
      indicesPut.push_back( 4);
      indicesPut.push_back( 5);
      indicesPut.push_back( 6);
      indicesPut.push_back( 7);
   } 

   static std::vector<double> dv;
   dv.resize(nVar);
   for (int ivar=0; ivar<nVar; ivar++) dv[ivar] = iv[indicesGet.at(ivar)];
   for (int ivar=0;ivar<8;ivar++) {
      double offset = fMin_1[cls][ivar];
      double scale  = 1.0/(fMax_1[cls][ivar]-fMin_1[cls][ivar]);
      iv[indicesPut.at(ivar)] = (dv[ivar]-offset)*scale * 2 - 1;
   }
}

//_______________________________________________________________________
inline void ReadMLP::InitTransform()
{
   InitTransform_1();
}

//_______________________________________________________________________
inline void ReadMLP::Transform( std::vector<double>& iv, int sigOrBgd ) const
{
   Transform_1( iv, sigOrBgd );
}
