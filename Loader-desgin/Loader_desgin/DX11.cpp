#include "DX11.h"
#include "Setting.h"
#include "DX11Window.h"

//#include "Setting.cpp"

LPDIRECT3DDEVICE9 DX11::pDevice = NULL;
IDirect3DSwapChain9* DX11::SwapChain = {};
LPDIRECT3D9 DX11::pD3D = NULL;
D3DPRESENT_PARAMETERS DX11::d3dpp = {};
LPD3DXFONT DX11::pPlayerNameFont = NULL;
LPDIRECT3DTEXTURE9 DX11::photo = NULL;
LPDIRECT3DTEXTURE9 DX11::mrboot = NULL;
LPDIRECT3DTEXTURE9 DX11::Image = NULL;
LPDIRECT3DTEXTURE9 DX11::Heart = NULL;
LPDIRECT3DTEXTURE9 DX11::LeftMenu = NULL;
LPDIRECT3DTEXTURE9 DX11::AirDrop = NULL;
LPDIRECT3DTEXTURE9 DX11::M24 = NULL;
LPDIRECT3DTEXTURE9 DX11::M416 = NULL;
LPDIRECT3DTEXTURE9 DX11::AKM = NULL;
LPDIRECT3DTEXTURE9 DX11::M762 = NULL;
LPDIRECT3DTEXTURE9 DX11::FLAREGUN = NULL;

LPDIRECT3DTEXTURE9 DX11::Helmet3 = NULL;
LPDIRECT3DTEXTURE9 DX11::Bag3 = NULL;
LPDIRECT3DTEXTURE9 DX11::Armor3 = NULL;

LPDIRECT3DTEXTURE9 DX11::HP0 = nullptr;
LPDIRECT3DTEXTURE9 DX11::HP25 = nullptr;
LPDIRECT3DTEXTURE9 DX11::HP50 = nullptr;
LPDIRECT3DTEXTURE9 DX11::HP75 = nullptr;
LPDIRECT3DTEXTURE9 DX11::HP100 = nullptr;
LPDIRECT3DTEXTURE9 DX11::Oil0 = nullptr;
LPDIRECT3DTEXTURE9 DX11::Oil10 = nullptr;
LPDIRECT3DTEXTURE9 DX11::Oil20 = nullptr;
LPDIRECT3DTEXTURE9 DX11::Oil40 = nullptr;
LPDIRECT3DTEXTURE9 DX11::Oil60 = nullptr;
LPDIRECT3DTEXTURE9 DX11::Oil75 = nullptr;
LPDIRECT3DTEXTURE9 DX11::Oil90 = nullptr;
LPDIRECT3DTEXTURE9 DX11::Oil100 = nullptr;

LPDIRECT3DTEXTURE9 DX11::AFFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::ALFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::DZFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::ASFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::ADFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::AOFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::AIFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::AQFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::AGFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::ARFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::AMFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::AWFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::AUFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::ATFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::AZFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::BSFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::BHFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::BDFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::BBFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::BYFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::BEFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::BZFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::BJFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::BMFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::BTFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::BOFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::BQFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::BAFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::BWFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::BVFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::BRFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::IOFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::BNFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::BGFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::BFFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::BIFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::CVFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::KHFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::CMFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::CAFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::KYFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::CFFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::TDFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::CLFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::CNFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::CXFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::CCFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::COFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::KMFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::CDFLAG = nullptr;
LPDIRECT3DTEXTURE9 DX11::CGFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::CKFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::CRFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::HRFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::CUFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::CWFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::CYFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::CZFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::CIFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::DKFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::DJFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::DMFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::DOFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::ECFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::EGFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::SVFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::GQFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::ERFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::EEFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::SZFLAG = nullptr;
LPDIRECT3DTEXTURE9 DX11::ETFLAG = nullptr;
LPDIRECT3DTEXTURE9 DX11::FKFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::FOFLAG = nullptr;
LPDIRECT3DTEXTURE9 DX11::FJFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::FIFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::FRFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::GFFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::PFFLAG = nullptr;
LPDIRECT3DTEXTURE9 DX11::TFFLAG = nullptr;
LPDIRECT3DTEXTURE9 DX11::GAFLAG = nullptr;
LPDIRECT3DTEXTURE9 DX11::GMFLAG = nullptr;
LPDIRECT3DTEXTURE9 DX11::GEFLAG = nullptr;
LPDIRECT3DTEXTURE9 DX11::DEFLAG = nullptr;
LPDIRECT3DTEXTURE9 DX11::GHFLAG = nullptr;
LPDIRECT3DTEXTURE9 DX11::GIFLAG = nullptr;
LPDIRECT3DTEXTURE9 DX11::GRFLAG = nullptr;
LPDIRECT3DTEXTURE9 DX11::GLFLAG = nullptr;
LPDIRECT3DTEXTURE9 DX11::GDFLAG = nullptr;
LPDIRECT3DTEXTURE9 DX11::GPFLAG = nullptr;
LPDIRECT3DTEXTURE9 DX11::GUFLAG = nullptr;
LPDIRECT3DTEXTURE9 DX11::GTFLAG = nullptr;
LPDIRECT3DTEXTURE9 DX11::GGFLAG = nullptr;
LPDIRECT3DTEXTURE9 DX11::GNFLAG = nullptr;
LPDIRECT3DTEXTURE9 DX11::GWFLAG = nullptr;
LPDIRECT3DTEXTURE9 DX11::GYFLAG = nullptr;
LPDIRECT3DTEXTURE9 DX11::HTFLAG = nullptr;
LPDIRECT3DTEXTURE9 DX11::HMFLAG = nullptr;
LPDIRECT3DTEXTURE9 DX11::VAFLAG = nullptr;
LPDIRECT3DTEXTURE9 DX11::HNFLAG = nullptr;
LPDIRECT3DTEXTURE9 DX11::HKFLAG = nullptr;
LPDIRECT3DTEXTURE9 DX11::HUFLAG = nullptr;
LPDIRECT3DTEXTURE9 DX11::JMFLAG = nullptr;
LPDIRECT3DTEXTURE9 DX11::G1FLAG = nullptr;
LPDIRECT3DTEXTURE9 DX11::JPFLAG = nullptr;
LPDIRECT3DTEXTURE9 DX11::JEFLAG = nullptr;
LPDIRECT3DTEXTURE9 DX11::JOFLAG = nullptr;
LPDIRECT3DTEXTURE9 DX11::KZFLAG = nullptr;
LPDIRECT3DTEXTURE9 DX11::KEFLAG = nullptr;
LPDIRECT3DTEXTURE9 DX11::KIFLAG = nullptr;
LPDIRECT3DTEXTURE9 DX11::KPFLAG = nullptr;
LPDIRECT3DTEXTURE9 DX11::KRFLAG = nullptr;
LPDIRECT3DTEXTURE9 DX11::KWFLAG = nullptr;
LPDIRECT3DTEXTURE9 DX11::KGFLAG = nullptr;
LPDIRECT3DTEXTURE9 DX11::LAFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::LVFLAG = nullptr;
LPDIRECT3DTEXTURE9 DX11::LBFLAG = nullptr;
LPDIRECT3DTEXTURE9 DX11::LSFLAG = nullptr;
LPDIRECT3DTEXTURE9 DX11::LRFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::LYFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::LIFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::LTFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::LUFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::MOFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::MGFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::MWFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::MYFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::MVFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::MLFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::MTFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::MHFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::MQFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::MRFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::MUFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::YTFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::MXFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::FMFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::MDFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::MCFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::MNFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::MEFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::MSFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::MAFLAG = nullptr;
LPDIRECT3DTEXTURE9 DX11::MZFLAG = nullptr;
LPDIRECT3DTEXTURE9 DX11::MMFLAG = nullptr;
LPDIRECT3DTEXTURE9 DX11::NAFLAG = nullptr;
LPDIRECT3DTEXTURE9 DX11::NRFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::NPFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::NLFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::NCFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::NZFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::NIFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::NEFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::NGFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::NUFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::NFFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::MPFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::NOFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::OMFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::PKFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::PWFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::PSFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::PAFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::PGFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::PYFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::PEFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::PHFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::PNFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::PLFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::PTFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::PRFLAG = nullptr;
LPDIRECT3DTEXTURE9 DX11::QAFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::MKFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::ROFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::RUFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::RWFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::REFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::BLFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::SHFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::KNFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::LCFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::MFFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::PMFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::VCFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::WSFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::SMFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::STFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::SAFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::SNFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::RSFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::SCFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::SLFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::SGFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::SXFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::SKFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::SIFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::SBFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::SOFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::ZAFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::GSFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::SSFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::ESFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::LKFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::SDFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::SRFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::SJFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::SEFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::CHFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::SYFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::TWFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::TJFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::TZFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::THFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::TLFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::TGFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::TKFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::TOFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::TTFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::TNFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::TRFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::TMFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::TCFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::TVFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::UGFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::UAFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::AEFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::GBFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::USFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::UYFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::UZFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::VUFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::VEFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::VNFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::VGFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::VIFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::WFFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::EHFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::YEFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::ZMFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::ZWFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::AXFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::ISFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::INFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::IDFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::IRFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::IQFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::IEFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::IMFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::ILFLAG = nullptr;

LPDIRECT3DTEXTURE9 DX11::ITFLAG = nullptr;


int DiffX;
int DiffY;
 
 
std::string string_To_UTF8(const std::string& str)
{
	int nwLen = ::MultiByteToWideChar(CP_ACP, 0, str.c_str(), -1, NULL, 0);

	wchar_t* pwBuf = new wchar_t[nwLen + 1];
	ZeroMemory(pwBuf, nwLen * 2 + 2);

	::MultiByteToWideChar(CP_ACP, 0, str.c_str(), str.length(), pwBuf, nwLen);

	int nLen = ::WideCharToMultiByte(CP_UTF8, 0, pwBuf, -1, NULL, NULL, NULL, NULL);

	char* pBuf = new char[nLen + 1];
	ZeroMemory(pBuf, nLen + 1);

	::WideCharToMultiByte(CP_UTF8, 0, pwBuf, nwLen, pBuf, nLen, NULL, NULL);

	std::string retStr(pBuf);

	delete[]pwBuf;
	delete[]pBuf;

	pwBuf = NULL;
	pBuf = NULL;

	return retStr;
}
 

BOOL DX11::Instantiate(HWND hWindow, INT Width, INT Height)
{
	//create the Direct3D interface
	pD3D = Direct3DCreate9(D3D_SDK_VERSION);
	if (pD3D == nullptr)
	{
		std::cout << "Direct3DCreate9 failed" << std::endl;
		return 0;
	}

	//create a struct to hold various device information
	d3dpp;
	ZeroMemory(&d3dpp, sizeof(d3dpp));    // clear out the struct for use
	d3dpp.Windowed = TRUE;    // program windowed, not fullscreen
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;    // discard old frames
	d3dpp.hDeviceWindow = hWindow;    // set the window to be used by Direct3D
	d3dpp.BackBufferFormat = D3DFMT_A8R8G8B8;     // set the back buffer format to 32-bit
	d3dpp.BackBufferWidth = Width;    // set the width of the buffer
	d3dpp.BackBufferHeight = Height;    // set the height of the buffer
	d3dpp.EnableAutoDepthStencil = TRUE;
	d3dpp.AutoDepthStencilFormat = D3DFMT_D16;
	d3dpp.MultiSampleType = D3DMULTISAMPLE_NONE;
	d3dpp.MultiSampleQuality = 0;
	d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;
	d3dpp.FullScreen_RefreshRateInHz = D3DPRESENT_RATE_DEFAULT;

	D3DCAPS9 caps;
	DWORD behaviorFlags;
	if (FAILED(pD3D->GetDeviceCaps(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, &caps))) {
		std::cout << "GetDeviceCaps failed" << std::endl;
		return 0;
	}
	if (caps.DevCaps & D3DDEVCAPS_HWTRANSFORMANDLIGHT) {
		behaviorFlags = D3DCREATE_HARDWARE_VERTEXPROCESSING;
		std::cout << "BehaviorFlags: D3DCREATE_HARDWARE_VERTEXPROCESSING" << std::endl;
	}
	else {
		behaviorFlags = D3DCREATE_SOFTWARE_VERTEXPROCESSING;
		std::cout << "BehaviorFlags: D3DCREATE_SOFTWARE_VERTEXPROCESSING" << std::endl;
	}

	// create a device class using this information and the info from the d3dpp stuct
	if (FAILED(pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWindow, behaviorFlags, &d3dpp, &pDevice)))
	{
		std::cout << "<D3D> CreateDevice failed!" << std::endl;
		return 0;
	}

 	D3DXCreateFont(pDevice, 20, 0, FW_REGULAR, 0, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH | FF_DONTCARE, TEXT("Microsoft Yahei"), &pPlayerNameFont);
	pD3D->Release();
	return 1;
 
}

FLOAT DX11::alpha = 0;
FLOAT  Transparent[4] = { 0,0,0,0 };

VOID DX11::BeginDraw()
{
	//pDevice->SetRenderState(D3DRS_ZENABLE, false);
	//pDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, false);
	//pDevice->SetRenderState(D3DRS_SCISSORTESTENABLE, false);
	//D3DVIEWPORT9 Veip; 
	//	pDevice->GetViewport(&Veip);
	//	Veip.Height = DX11Window::Height;
	//	Veip.Width = DX11Window::Width;
	//
	// pDevice->SetViewport(&Veip);
	pDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_ARGB(0, 0, 0, 0), 1.0f, 0);

	// pDevice->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, 0, 0.0f, 0);  
	pDevice->BeginScene();
//	pImmediateContext->ClearDepthStencilView(pDepthStencilView, D3D11_CLEAR_DEPTH, 1.0f, 0);
}

VOID DX11::ClearSurface()
{
	//pImmediateContext->ClearRenderTargetView(pRenderTargetView, Transparent);
	//pImmediateContext->ClearDepthStencilView(pDepthStencilView, D3D11_CLEAR_DEPTH, 1.0f, 0);
}

VOID DX11::EndDraw()
{
	pDevice->EndScene();  
 //	RECT RECT;
// 	GetWindowRect(Game::hWindow, &RECT);
	pDevice->Present(0, NULL, NULL, NULL);
}

 
 
VOID DX11::ImGui_DX11::IMGUIDRAWLINE(FLOAT X1, FLOAT Y1, FLOAT X2, FLOAT Y2, ImColor Color, FLOAT Thickness)
{
	ImGuiWindow* window = ImGui::GetCurrentWindow();

	window->DrawList->AddLine(ImVec2(X1, Y1), ImVec2(X2, Y2), Color, Thickness);

}
VOID DX11::ImGui_DX11::IMGUIDRAWCIRCLE(FLOAT X, FLOAT Y, FLOAT Radius, ImColor Color, FLOAT Thickness)
{
	ImGuiWindow* window = ImGui::GetCurrentWindow();
	window->DrawList->AddCircle(ImVec2(X, Y), Radius, Color, 0, Thickness);

}
void DX11::ImGui_DX11::FillTriangle(int x1, int y1, int x2, int y2, int x3, int y3, float thickness, ImColor color) {
	pImGuiDraw = ImGui::GetBackgroundDrawList();
	DrawLine(x1, y1, x2, y2, color, thickness);
	DrawLine(x2, y2, x3, y3, color, thickness);
	DrawLine(x3, y3, x1, y1, color, thickness);
	for (int x = x1; x <= x2; x++) {
		for (int y = y1; y <= y2; y++) {
			DrawLine(x3, y3, x, y, color, thickness);
		}
	}
}
 

ImDrawList* DX11::ImGui_DX11::pImGuiDraw;
ImFont* DX11::ImGui_DX11::pRegularFont;
ImFont* DX11::ImGui_DX11::special;
ImFont* DX11::ImGui_DX11::khaledmalki;
ImFont* DX11::ImGui_DX11::pic;

ImFont* DX11::ImGui_DX11::MainFont;
ImFont* DX11::ImGui_DX11::Arabic;
ImFont* DX11::ImGui_DX11::Arabicc;
ImFont* DX11::ImGui_DX11::Arial;
ImFont* DX11::ImGui_DX11::Tahoma;
ImFont* DX11::ImGui_DX11::TahomaBold;
ImFont* DX11::ImGui_DX11::Verdana;
ImFont* DX11::ImGui_DX11::ComicSansMS;
ImFont* DX11::ImGui_DX11::Shadeon;
void DX11::ImGui_DX11::CornerBox(int x, int y, int w, int h, int thickness, float cornered, ImColor color)
{
	// Left Top
	DrawLine(x, y, x + (w * cornered), y, color, thickness);
	DrawLine(x, y, x, y + (h * cornered), color, thickness);
	// Left Bottom
	DrawLine(x, y + h, x + (w * cornered), y + h, color, thickness);
	DrawLine(x, y + h, x, (y + h) - (h * cornered), color, thickness);
	// Right Top
	DrawLine(x + w, y, (x + w) - (w * cornered), y, color, thickness);
	DrawLine(x + w, y, x + w, y + (h * cornered), color, thickness);
	// Right Bottom
	DrawLine(x + w, y + h, (x + w) - (w * cornered), y + h, color, thickness);
	DrawLine(x + w, y + h, x + w, (y + h) - (h * cornered), color, thickness);
}
VOID DX11::ImGui_DX11::DrawLine(FLOAT X1, FLOAT Y1, FLOAT X2, FLOAT Y2, ImColor Color, FLOAT Thickness)
{
	pImGuiDraw = ImGui::GetBackgroundDrawList();
	pImGuiDraw->AddLine(ImVec2(X1, Y1), ImVec2(X2, Y2), Color, Thickness);
}
void DX11::ImGui_DX11::AimLine(int x, int y, int x1, int y1, ImColor color, float thickness)
{
	//  ImGuiWindow* window = ImGui::GetOverlayDrawList();

	float a = (color >> 24) & 0xff;
	float r = (color >> 16) & 0xff;
	float g = (color >> 8) & 0xff;
	float b = (color) & 0xff;
	pImGuiDraw->AddLine(ImVec2(x, y), ImVec2(x1, y1),
		ImGui::GetColorU32(ImVec4(r / 255, g / 255, b / 255, a / 255)), thickness);


}


VOID DX11::ImGui_DX11::DrawCircle(FLOAT X, FLOAT Y, FLOAT Radius, ImColor Color, FLOAT Thickness)
{
	pImGuiDraw = ImGui::GetBackgroundDrawList();
	pImGuiDraw->AddCircle(ImVec2(X, Y), Radius, Color, 0, Thickness);

}
VOID DX11::ImGui_DX11::DrawCircle2(FLOAT X, FLOAT Y, FLOAT Radius, ImColor Color, FLOAT Thickness)
{
	pImGuiDraw = ImGui::GetBackgroundDrawList();
	pImGuiDraw->AddCircleFilled(ImVec2(X, Y), Radius, Color, 0);

}
VOID DX11::ImGui_DX11::Tri(FLOAT X, FLOAT Y, ImColor Color)
{
	pImGuiDraw = ImGui::GetBackgroundDrawList();
	pImGuiDraw->AddTriangleFilled(ImVec2(X, Y), ImVec2(X, Y), ImVec2(Y, X), Color);

}

VOID DX11::ImGui_DX11::DrawRectangle(FLOAT X, FLOAT Y, FLOAT Width, FLOAT Height, ImColor Color, FLOAT Thickness)
{
	pImGuiDraw = ImGui::GetBackgroundDrawList();
	pImGuiDraw->AddRect(ImVec2(X, Y), ImVec2(X + Width, Y + Height), Color, 0, 0, Thickness);
}
void DX11::ImGui_DX11::DrawFilledRect(int x, int y, int w, int h, uint32_t color)
{

	float a = (color >> 24) & 0xff;
	float r = (color >> 16) & 0xff;
	float g = (color >> 8) & 0xff;
	float b = (color) & 0xff;

	pImGuiDraw->AddRectFilled(ImVec2(x, y - 1), ImVec2(x + w, y + h), ImGui::ColorConvertFloat4ToU32(ImVec4(r / 255.0, g / 255.0, b / 255.0, 1 / 255.0)), 0, 0);
	pImGuiDraw->AddRectFilled(ImVec2(x, y + 1), ImVec2(x + w, y + h), ImGui::ColorConvertFloat4ToU32(ImVec4(r / 255.0, g / 255.0, b / 255.0, 1 / 255.0)), 0, 0);
	pImGuiDraw->AddRectFilled(ImVec2(x - 1, y), ImVec2(x + w, y + h), ImGui::ColorConvertFloat4ToU32(ImVec4(r / 255.0, g / 255.0, b / 255.0, 1 / 255.0)), 0, 0);
	pImGuiDraw->AddRectFilled(ImVec2(x + 1, y), ImVec2(x + w, y + h), ImGui::ColorConvertFloat4ToU32(ImVec4(r / 255.0, g / 255.0, b / 255.0, 1 / 255.0)), 0, 0);
	pImGuiDraw->AddRectFilled(ImVec2(x, y), ImVec2(x + w, y + h), ImGui::ColorConvertFloat4ToU32(ImVec4(r / 255.0, g / 255.0, b / 255.0, a / 255.0)), 0, 0);
}

VOID DX11::ImGui_DX11::DrawUnHP(FLOAT X, FLOAT Y, FLOAT W, FLOAT H, ImColor Color)
{
	pImGuiDraw = ImGui::GetBackgroundDrawList();

	pImGuiDraw->AddRect(ImVec2(X, Y), ImVec2(X - W, Y - H), Color, 0, 0, 1);
}

VOID DX11::ImGui_DX11::DrawHP(FLOAT X, FLOAT Y, FLOAT W, FLOAT H, ImColor Color)
{
	pImGuiDraw = ImGui::GetBackgroundDrawList();
	pImGuiDraw->AddRectFilled(ImVec2(X, Y), ImVec2(X - W, Y - H), Color);
}

VOID DX11::ImGui_DX11::DrawFilledRectangle(FLOAT X, FLOAT Y, FLOAT W, FLOAT H, ImColor Color)
{
	pImGuiDraw = ImGui::GetBackgroundDrawList();
	pImGuiDraw->AddRectFilled(ImVec2(X, Y), ImVec2(X - W, Y - H), Color);
}
VOID DX11::ImGui_DX11::DrawUnFilledRectangle(FLOAT X, FLOAT Y, FLOAT W, FLOAT H, ImColor Color)
{
	pImGuiDraw = ImGui::GetBackgroundDrawList();

	pImGuiDraw->AddRect(ImVec2(X, Y), ImVec2(X - W, Y - H), Color, 0, 0, 1);
}
VOID DX11::ImGui_DX11::DrawUnFilledRectangle2(FLOAT X, FLOAT Y, FLOAT W, FLOAT H, ImColor Color)
{
	pImGuiDraw = ImGui::GetBackgroundDrawList();

	pImGuiDraw->AddRect(ImVec2(X, Y), ImVec2(X + W, Y + H), Color, 0, 0, 1);
}
VOID  DX11::ImGui_DX11::DrawImage(LPDIRECT3DTEXTURE9 img, int x, int y, int sizex, int sizey) {
	ImGui::GetBackgroundDrawList()->AddImage(img, ImVec2(x, y), ImVec2(x + sizex, y + sizey));
}
void DX11::ImGui_DX11::DrawBlood(float x, float y, float w, float h, float fBlood)
{

	if (fBlood > 70.0)
	{

		DrawFilledRect(x, y, w * fBlood / 100, h, ImColor(0.0f, 1.0f, 0.0f, 1.0f));

	}
	if (fBlood > 30.0 && fBlood <= 70.0)
	{

		DrawFilledRect(x, y, w * fBlood / 100, h, ImColor(1.0f, 0.0f, 0.0f, 1.0f));

	}
	if (fBlood > 0.0 && fBlood <= 30.0)
	{

		DrawFilledRect(x, y, w * fBlood / 100, h, ImColor(0.0f, 0.0f, 1.0f, 1.0f));


	}
	CornerBox(x, y, w, h, 2, 1.0, ImColor(0.0f, 0.0f, 0.0f, 0.5f));
}
void DX11::ImGui_DX11::DrawBlood2(float x, float y, float w, float h, float fBlood)
{

	if (fBlood > 70.0)
	{

		DrawFilledRect(x, y, w * fBlood / 100, h, ImColor(0.2f, 0.8f, 1.0f, 1.0f));

	}
	if (fBlood > 30.0 && fBlood <= 70.0)
	{

		DrawFilledRect(x, y, w * fBlood / 100, h, ImColor(1.0f, 0.0f, 0.0f, 1.0f));

	}
	if (fBlood > 0.0 && fBlood <= 30.0)
	{

		DrawFilledRect(x, y, w * fBlood / 100, h, ImColor(0.0f, 0.0f, 1.0f, 1.0f));


	}
	CornerBox(x, y, w, h, 2, 1.0, ImColor(0.0f, 0.0f, 0.0f, 0.5f));
}




VOID DX11::ImGui_DX11::DrawString(ImFont* pFont, FLOAT FontSize, string& Text, FLOAT X, FLOAT Y, ImColor Color, bool Center)
{
	pImGuiDraw = ImGui::GetBackgroundDrawList();

	if (Center)
	{
		ImVec2 TextSize = pFont->CalcTextSizeA(FontSize, FLT_MAX, 0.0f, Text.c_str());
		pImGuiDraw->AddText(pFont, FontSize, ImVec2(X - TextSize.x / 2.0f, Y), Color, Text.c_str());
	}
	else
	{
		pImGuiDraw->AddText(pFont, FontSize, ImVec2(X, Y), Color, Text.c_str());
	}
}


VOID DX11::ImGui_DX11::DrawStringchar(ImFont* pFont, FLOAT FontSize, const char*& Text, FLOAT X, FLOAT Y, ImColor Color, bool Center)
{
	pImGuiDraw = ImGui::GetBackgroundDrawList();

	if (Center)
	{
		ImVec2 TextSize = pFont->CalcTextSizeA(FontSize, FLT_MAX, 0.0f, Text );
		pImGuiDraw->AddText(pFont, FontSize, ImVec2(X - TextSize.x / 2.0f, Y), Color, Text );
	}
	else
	{
		pImGuiDraw->AddText(pFont, FontSize, ImVec2(X, Y), Color, Text );
	}
}
VOID DX11::ImGui_DX11::DrawStringchar1(ImFont* pFont, FLOAT FontSize,  char*& Text, FLOAT X, FLOAT Y, ImColor Color, bool Center)
{
	pImGuiDraw = ImGui::GetBackgroundDrawList();

	if (Center)
	{
		ImVec2 TextSize = pFont->CalcTextSizeA(FontSize, FLT_MAX, 0.0f, Text);
		pImGuiDraw->AddText(pFont, FontSize, ImVec2(X - TextSize.x / 2.0f, Y), Color, Text);
	}
	else
	{
		pImGuiDraw->AddText(pFont, FontSize, ImVec2(X, Y), Color, Text);
	}
}

void DX11::ImGui_DX11::DrawStrokeText(ImFont* pFont, int x, int y, ImColor Color, const char* str, float fontsize, bool center)
{
	if (center)
	{
		auto textisze = pFont->CalcTextSizeA(fontsize, FLT_MAX, 0, str);
		x -= textisze.x / 2;
		y -= textisze.y / 2;
	}
	ImFont a;
	ImGui::GetOverlayDrawList()->AddText(pFont, fontsize, ImVec2(x - 0.1, y), ImGui::ColorConvertFloat4ToU32(ImVec4(0 / 255.0, 0 / 255.0, 0 / 255.0, 255 / 255.0)), str);
	ImGui::GetOverlayDrawList()->AddText(pFont, fontsize, ImVec2(x + 0.1, y), ImGui::ColorConvertFloat4ToU32(ImVec4(0 / 255.0, 0 / 255.0, 0 / 255.0, 255 / 255.0)), str);
	ImGui::GetOverlayDrawList()->AddText(pFont, fontsize, ImVec2(x, y - 0.1), ImGui::ColorConvertFloat4ToU32(ImVec4(0 / 255.0, 0 / 255.0, 0 / 255.0, 255 / 255.0)), str);
	ImGui::GetOverlayDrawList()->AddText(pFont, fontsize, ImVec2(x, y + 0.1), ImGui::ColorConvertFloat4ToU32(ImVec4(0 / 255.0, 0 / 255.0, 0 / 255.0, 255 / 255.0)), str);
	ImGui::GetOverlayDrawList()->AddText(pFont, fontsize, ImVec2(x, y), Color, str);
}
VOID DX11::ImGui_DX11::DrawWStringBorderText(ImFont* pFont, FLOAT size, const char* str, FLOAT x, FLOAT y, ImColor Color, bool Center)
{
	
	//ImGui::GetOverlayDrawList()->AddText(pFont, size, ImVec2(x, y), ImGui::ColorConvertFloat4ToU32(ImVec4(color->R / 255.0, color->G / 255.0, color->B / 255.0, color->A / 255.0)), utf_8_2.c_str());
	if (Center)
	{
		ImVec2 TextSize = pFont->CalcTextSizeA(size, FLT_MAX, 0.0f, str);
		//ImGui::GetOverlayDrawList()->AddText(pFont, size, ImVec2(x, y), ImGui::ColorConvertFloat4ToU32(ImVec4(color->R / 255.0, color->G / 255.0, color->B / 255.0, color->A / 255.0)), utf_8_2.c_str());
		ImGui::GetOverlayDrawList()->AddText(pFont, size, ImVec2((x - TextSize.x / 2.0f) - 0.1, y ), ImGui::ColorConvertFloat4ToU32(ImVec4(0 / 255.0, 0 / 255.0, 0 / 255.0, 255 / 255.0)), str);
		ImGui::GetOverlayDrawList()->AddText(pFont, size, ImVec2((x - TextSize.x / 2.0f) + 0.1, y ), ImGui::ColorConvertFloat4ToU32(ImVec4(0 / 255.0, 0 / 255.0, 0 / 255.0, 255 / 255.0)), str);
		ImGui::GetOverlayDrawList()->AddText(pFont, size, ImVec2((x - TextSize.x / 2.0f), y - 0.1), ImGui::ColorConvertFloat4ToU32(ImVec4(0 / 255.0, 0 / 255.0, 0 / 255.0, 255 / 255.0)), str);
		ImGui::GetOverlayDrawList()->AddText(pFont, size, ImVec2((x - TextSize.x / 2.0f), y + 0.1), ImGui::ColorConvertFloat4ToU32(ImVec4(0 / 255.0, 0 / 255.0, 0 / 255.0, 255 / 255.0)), str);
		ImGui::GetOverlayDrawList()->AddText(pFont, size, ImVec2((x - TextSize.x / 2.0f), y), Color, str);
	}
	else
	{

		ImGui::GetOverlayDrawList()->AddText(pFont, size, ImVec2(x - 0.1, y), ImGui::ColorConvertFloat4ToU32(ImVec4(0 / 255.0, 0 / 255.0, 0 / 255.0, 255 / 255.0)), str);
		ImGui::GetOverlayDrawList()->AddText(pFont, size, ImVec2(x + 0.1, y), ImGui::ColorConvertFloat4ToU32(ImVec4(0 / 255.0, 0 / 255.0, 0 / 255.0, 255 / 255.0)), str);
		ImGui::GetOverlayDrawList()->AddText(pFont, size, ImVec2(x, y - 0.1), ImGui::ColorConvertFloat4ToU32(ImVec4(0 / 255.0, 0 / 255.0, 0 / 255.0, 255 / 255.0)), str);
		ImGui::GetOverlayDrawList()->AddText(pFont, size, ImVec2(x, y + 0.1), ImGui::ColorConvertFloat4ToU32(ImVec4(0 / 255.0, 0 / 255.0, 0 / 255.0, 255 / 255.0)), str);
		ImGui::GetOverlayDrawList()->AddText(pFont, size, ImVec2(x , y ), Color, str);
	}
}
VOID DX11::ImGui_DX11::DrawBorderString(ImFont* pFont, FLOAT size, string& Text, FLOAT x, FLOAT y, ImColor Color, bool Center)
{
	
	std::string utf_8_1 = std::string(Text);
	std::string utf_8_2 = string_To_UTF8(utf_8_1);
	//ImGui::GetOverlayDrawList()->AddText(pFont, size, ImVec2(x, y), ImGui::ColorConvertFloat4ToU32(ImVec4(color->R / 255.0, color->G / 255.0, color->B / 255.0, color->A / 255.0)), utf_8_2.c_str());
	ImGui::GetOverlayDrawList()->AddText(pFont, size, ImVec2(x + DiffX, y - 1 + DiffY), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), utf_8_2.c_str());
	ImGui::GetOverlayDrawList()->AddText(pFont, size, ImVec2(x + DiffX, y + 1 + DiffY), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), utf_8_2.c_str());
	ImGui::GetOverlayDrawList()->AddText(pFont, size, ImVec2(x - 1 + DiffX, y + DiffY), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), utf_8_2.c_str());
	ImGui::GetOverlayDrawList()->AddText(pFont, size, ImVec2(x + 1 + DiffX, y + DiffY), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), utf_8_2.c_str());
	ImGui::GetOverlayDrawList()->AddText(pFont, size, ImVec2(x + DiffX, y + DiffY), Color, utf_8_2.c_str());
}

VOID DX11::ImGui_DX11::DrawBorderText(ImFont* pFont, FLOAT size, string& Text, FLOAT x, FLOAT y, ImColor Color, bool Center)
{
	std::string utf_8_1 = std::string(Text);
	std::string utf_8_2 = string_To_UTF8(utf_8_1);
	//ImGui::GetOverlayDrawList()->AddText(pFont, size, ImVec2(x, y), ImGui::ColorConvertFloat4ToU32(ImVec4(color->R / 255.0, color->G / 255.0, color->B / 255.0, color->A / 255.0)), utf_8_2.c_str());
	if (Center)
	{
		ImVec2 TextSize = pFont->CalcTextSizeA(size, FLT_MAX, 0.0f, Text.c_str());
		//ImGui::GetOverlayDrawList()->AddText(pFont, size, ImVec2(x, y), ImGui::ColorConvertFloat4ToU32(ImVec4(color->R / 255.0, color->G / 255.0, color->B / 255.0, color->A / 255.0)), utf_8_2.c_str());
		ImGui::GetOverlayDrawList()->AddText(pFont, size, ImVec2((x - TextSize.x / 2.0f) + DiffX, y - 1 + DiffY), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), utf_8_2.c_str());
		ImGui::GetOverlayDrawList()->AddText(pFont, size, ImVec2((x - TextSize.x / 2.0f) + DiffX, y + 1 + DiffY), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), utf_8_2.c_str());
		ImGui::GetOverlayDrawList()->AddText(pFont, size, ImVec2((x - TextSize.x / 2.0f) - 1 + DiffX, y + DiffY), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), utf_8_2.c_str());
		ImGui::GetOverlayDrawList()->AddText(pFont, size, ImVec2((x - TextSize.x / 2.0f) + 1 + DiffX, y + DiffY), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), utf_8_2.c_str());
		ImGui::GetOverlayDrawList()->AddText(pFont, size, ImVec2((x - TextSize.x / 2.0f) + DiffX, y + DiffY), Color, utf_8_2.c_str());
	}
	else
	{

		ImGui::GetOverlayDrawList()->AddText(pFont, size, ImVec2(x + DiffX, y - 1 + DiffY), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), utf_8_2.c_str());
		ImGui::GetOverlayDrawList()->AddText(pFont, size, ImVec2(x + DiffX, y + 1 + DiffY), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), utf_8_2.c_str());
		ImGui::GetOverlayDrawList()->AddText(pFont, size, ImVec2(x - 1 + DiffX, y + DiffY), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), utf_8_2.c_str());
		ImGui::GetOverlayDrawList()->AddText(pFont, size, ImVec2(x + 1 + DiffX, y + DiffY), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), utf_8_2.c_str());
		ImGui::GetOverlayDrawList()->AddText(pFont, size, ImVec2(x + DiffX, y + DiffY), Color, utf_8_2.c_str());
	}
}

VOID DX11::ImGui_DX11::DrawCharBorderText(ImFont* pFont, FLOAT size, const char* str, FLOAT x, FLOAT y, ImColor Color, bool Center)
{
	std::string utf_8_1 = std::string(str);
	std::string utf_8_2 = string_To_UTF8(utf_8_1);
	//ImGui::GetOverlayDrawList()->AddText(pFont, size, ImVec2(x, y), ImGui::ColorConvertFloat4ToU32(ImVec4(color->R / 255.0, color->G / 255.0, color->B / 255.0, color->A / 255.0)), utf_8_2.c_str());
	if (Center)
	{
		ImVec2 TextSize = pFont->CalcTextSizeA(size, FLT_MAX, 0.0f, str);
		//ImGui::GetOverlayDrawList()->AddText(pFont, size, ImVec2(x, y), ImGui::ColorConvertFloat4ToU32(ImVec4(color->R / 255.0, color->G / 255.0, color->B / 255.0, color->A / 255.0)), utf_8_2.c_str());
		ImGui::GetOverlayDrawList()->AddText(pFont, size, ImVec2((x - TextSize.x / 2.0f) + DiffX, y - 1 + DiffY), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), utf_8_2.c_str());
		ImGui::GetOverlayDrawList()->AddText(pFont, size, ImVec2((x - TextSize.x / 2.0f) + DiffX, y + 1 + DiffY), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), utf_8_2.c_str());
		ImGui::GetOverlayDrawList()->AddText(pFont, size, ImVec2((x - TextSize.x / 2.0f) - 1 + DiffX, y + DiffY), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), utf_8_2.c_str());
		ImGui::GetOverlayDrawList()->AddText(pFont, size, ImVec2((x - TextSize.x / 2.0f) + 1 + DiffX, y + DiffY), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), utf_8_2.c_str());
		ImGui::GetOverlayDrawList()->AddText(pFont, size, ImVec2((x - TextSize.x / 2.0f) + DiffX, y + DiffY), Color, utf_8_2.c_str());
	}
	else
	{

		ImGui::GetOverlayDrawList()->AddText(pFont, size, ImVec2(x + DiffX, y - 1 + DiffY), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), utf_8_2.c_str());
		ImGui::GetOverlayDrawList()->AddText(pFont, size, ImVec2(x + DiffX, y + 1 + DiffY), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), utf_8_2.c_str());
		ImGui::GetOverlayDrawList()->AddText(pFont, size, ImVec2(x - 1 + DiffX, y + DiffY), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), utf_8_2.c_str());
		ImGui::GetOverlayDrawList()->AddText(pFont, size, ImVec2(x + 1 + DiffX, y + DiffY), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), utf_8_2.c_str());
		ImGui::GetOverlayDrawList()->AddText(pFont, size, ImVec2(x + DiffX, y + DiffY), Color, utf_8_2.c_str());
	}
}
void DX11::ImGui_DX11::DrawTriangle(int x1, int y1, int x2, int y2, int x3, int y3, float thickness, ImColor color) {
	pImGuiDraw = ImGui::GetBackgroundDrawList();
	DrawLine(x1, y1, x2, y2, color, thickness);
	DrawLine(x2, y2, x3, y3, color, thickness);
	DrawLine(x3, y3, x1, y1, color, thickness);
}
VOID DX11::ImGui_DX11::SpText(ImFont* pFont, FLOAT FontSize, string& Text, FLOAT X, FLOAT Y, ImColor Color, bool Center)
{
	pImGuiDraw = ImGui::GetBackgroundDrawList();

	if (Center)
	{
		ImVec2 TextSize = pFont->CalcTextSizeA(FontSize, FLT_MAX, 0.0f, Text.c_str());
		pImGuiDraw->AddText(pFont, FontSize, ImVec2((X - TextSize.x / 2.0f) + 1.0f, Y + 1.0f), Color, Text.c_str());
		pImGuiDraw->AddText(pFont, FontSize, ImVec2((X - TextSize.x / 2.0f) - 1.0f, Y - 1.0f), Color, Text.c_str());
		pImGuiDraw->AddText(pFont, FontSize, ImVec2((X - TextSize.x / 2.0f) + 1.0f, Y - 1.0f), Color, Text.c_str());
		pImGuiDraw->AddText(pFont, FontSize, ImVec2((X - TextSize.x / 2.0f) - 1.0f, Y + 1.0f), Color, Text.c_str());
		pImGuiDraw->AddText(pFont, FontSize, ImVec2(X - TextSize.x / 2.0f, Y), Color, Text.c_str());
	}
	else
	{
		pImGuiDraw->AddText(pFont, FontSize, ImVec2(X, Y - 2.0f), Color, Text.c_str());
		pImGuiDraw->AddText(pFont, FontSize, ImVec2(X, Y + 2.0f), Color, Text.c_str());
		pImGuiDraw->AddText(pFont, FontSize, ImVec2(X - 2.0f, Y), Color, Text.c_str());
		pImGuiDraw->AddText(pFont, FontSize, ImVec2(X + 2.0f, Y), Color, Text.c_str());
		pImGuiDraw->AddText(pFont, FontSize, ImVec2(X, Y), Color, Text.c_str());
	}
}