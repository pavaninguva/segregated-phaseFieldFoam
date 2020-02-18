// if (nAlphaSubCycles > 1)
// {
//     dimensionedScalar totalDeltaT = runTime.deltaT();
//     surfaceScalarField rhoPhiSum
//     (
//         IOobject
//         (
//             "rhoPhiSum",
//             runTime.timeName(),
//             mesh
//         ),
//         mesh,
//         dimensionedScalar(rhoPhi.dimensions(), Zero)
//     );

//     tmp<volScalarField> trSubDeltaT;

//     if (LTS)
//     {
//         trSubDeltaT =
//             fv::localEulerDdt::localRSubDeltaT(mesh, nAlphaSubCycles);
//     }

//     for
//     (
//         subCycle<volScalarField> alphaSubCycle(alpha1, nAlphaSubCycles);
//         !(++alphaSubCycle).end();
//     )
//     {
//         #include "alphaEqn.H"
//         rhoPhiSum += (runTime.deltaT()/totalDeltaT)*rhoPhi;
//     }

//     rhoPhi = rhoPhiSum;
// }
// else
// {
//     #include "alphaEqn.H"
// }

#include "alphaEqn.H"

// This implementation is for the VoF method. Change to PF method
//rho == alpha1*rho1 + alpha2*rho2;

rho == 0.5*(rho1*(1+alpha1) + rho2*(1-alpha1));

// Next we add the viscosity stuff: 

volScalarField& nuTemp = const_cast<volScalarField&>(mixture.nu()());
nuTemp == 0.5*(nu1*(1+alpha1) + nu2*(1-alpha1));