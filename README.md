# TMVA Analysis

The events from background and the signal sample are categorized based on three muon mass resolution.  For training the BDT the background samples are further classified into two categories based on the sidebands region they are inF (right or left).  For training half the events are used and for testing the rest half is used. As an example, NewTMVAVars was given as a 
The following features were used to train the BDT:

1. var_vertexKFChi2 (chi sq of the fit of the secondary vertex)
2. var_svpvTauAngle (The angle between PV-SV vector and the tau vector)
3. var_flightLenSig (Flight length significance of the tau candidate)
4. var_sumMuTrkKinkChi2 (sum of chi sq of the kink of all three muons)
5. var_segCompMuMin (Minimum of the segment compatibility of the three muons)
6. var_MinMIPLikelihood (Minimum of the calorimeter compatibility of the three muons)

## Description of the categories
Background:

| BDT category | Description |
| :---: | :---: |
| 1 | tauMassRes<0.007 && threeMuMass<1.78 |
| 2 | tauMassRes>0.007 && tauMassRes<0.01 && threeMuMass<1.78 |
| 3 | tauMassRes>0.01 && threeMuMass<1.78 |
| 4 | tauMassRes<0.007 && threeMuMass>1.78 |
| 5 | tauMassRes>0.007 && tauMassRes<0.01 && threeMuMass>1.78 |
| 6 | tauMassRes>0.01 && threeMuMass>1.78 |

Signal:

| BDT category | Description |
| :---: | :---: |
| 1 | tauMassRes<0.007 |
| 2 | tauMassRes>0.007 && tauMassRes<0.01 |
| 3 | tauMassRes>0.01 |

| Classifier | Description |
| :---: | :---: |
| 1 | Background category 1 trained with signal category 1 |
| 2 | Background category 2 trained with signal category 2 |
| 3 | Background category 3 trained with signal category 3 |
| 4 | Background category 4 trained with signal category 4 |
| 5 | Background category 5 trained with signal category 5 |
| 6 | Background category 6 trained with signal category 6 |
| 7 | Background category 1 and 4 trained with signal category 1 |
| 8 | Background category 2 and 5 trained with signal category 2 |
| 9 | Background category 3 and 6 trained with signal category 3 |
