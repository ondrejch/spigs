/*
 * PigsGUI.h
 * Single channel version
 *
 *  Created on: Jun 19, 2015
 *      Author: Ondrej Chvala <ochvala@utk.edu>
 */

#ifndef PIGSGUI_H_
#define PIGSGUI_H_

#include "Riostream.h"
#include "TGTab.h"
#include "TGLabel.h"
#include "TRootEmbeddedCanvas.h"
#include "TGProgressBar.h"
#include "TGButton.h"
#include "TCanvas.h"
#include "TGClient.h"

#include "PigsDAQ.h"

class PigsGUI : public TGMainFrame  {
public:
	PigsGUI();						// Creates the GUI
	~PigsGUI();						// Ends DAQ, DPP, GUI
	int InitDAQ();					// Initialization of the PigsDAQ object, DPP library, DAQ config
	int ExitDAQ();					// Ends connection to the DPP library
	int StartAcqisition();
	int StopAcqisition();			// Stops acquisition on channel 0
    void SetProgressBarPosition(Float_t fposition);	// Set the position of the progress bar

private:
	TGMainFrame *fMainGUIFrame;		// Main GUI window
	TGLabel *fMainTitle;			//
	TGTab *fTabHolder;  			// tab widget
	TGCompositeFrame *fCurHistFrame;// container of "CurrentHistogram"
	TRootEmbeddedCanvas *fLatestHistoCanvas;
	TCanvas *cCurrHCanvas;
	TGHProgressBar *fHCurrHProgressBar;
	TGCompositeFrame *fTabHisto;	// container of "History"
	TRootEmbeddedCanvas *fLastNspectra;
	TCanvas *cLastNspectra;
	TGCompositeFrame *fTabConfig; 	// container of "Config"
	TGCompositeFrame *fTABDT5781; 	// container of "DT5781"
	TGCompositeFrame *fTabAbout;  	// container of "About"

	TGTextButton *fStartDAQ, *fStopDAQ, *fExitDAQ; // buttons

	TGFont *ufont;         			// will reflect user font changes
	ULong_t fColor; 		  		// Color helper
	TGGC   *uGC;           			// will reflect user GC changes
	GCValues_t valTitle;			// graphics context changes

	const int fGUIsizeX = 600;
	const int fGUIsizeY = 500;

	PigsDAQ *daq;

	ClassDef(PigsGUI, 0)
};

#endif /* PIGSGUI_H_ */
