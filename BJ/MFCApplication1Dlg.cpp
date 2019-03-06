
// MFCApplication1Dlg.cpp: файл реализации
//
#define _CRT_SECURE_NO_WARNINGS
#include "stdafx.h"
#include "MFCApplication1.h"
#include "MFCApplication1Dlg.h"
#include "afxdialogex.h"

#include <string>
#include <sstream>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
const char* diller_cards[10] = { "2","3","4","5","6","7","8","9","10","A"};
const char* user_cards[26] = { "8<","9","10","11","12","13","14","15","16",">17",">A-8","A-7","A-6","A-5","A-4","A-3","A-2","A-A","10-10","9-9","8-8","7-7","6-6","5-5","4-4","3-3,2-2" };
const char* results[4] = { "Hit","Stop","Double","Split" };
// Диалоговое окно CAboutDlg используется для описания сведений о приложении

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

// Реализация
protected:
	DECLARE_MESSAGE_MAP()
};



CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}


void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()



// Диалоговое окно CMFCApplication1Dlg



CMFCApplication1Dlg::CMFCApplication1Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION1_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCApplication1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CMFCApplication1Dlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication1Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCApplication1Dlg::OnBnClickedButton2)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CMFCApplication1Dlg::OnLbnSelchangeList1)
	ON_CBN_SELCHANGE(IDC_COMBO2, &CMFCApplication1Dlg::OnLbnSelchangeList2)
	//ON_CBN_DROPDOWN(IDC_COMBO1, &CMFCApplication1Dlg::OnLbnSelchangeList1)
	ON_STN_CLICKED(IDC_STATIC_MY1, &CMFCApplication1Dlg::OnStnClickedStaticMy1)
END_MESSAGE_MAP()


// Обработчики сообщений CMFCApplication1Dlg

BOOL CMFCApplication1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	CComboBox *combo_diller = (CComboBox *)GetDlgItem(IDC_COMBO1);
	CComboBox *combo_user = (CComboBox *)GetDlgItem(IDC_COMBO2);
	for(int i=0;i<10;i++)
		combo_diller->AddString(diller_cards[i]);
	for (int i=0;i<26;i++)
		combo_user->AddString(user_cards[i]);
	// Добавление пункта "О программе..." в системное меню.

	// IDM_ABOUTBOX должен быть в пределах системной команды.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Задает значок для этого диалогового окна.  Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	// TODO: добавьте дополнительную инициализацию
//	MessageBox((LPCTSTR)(char*)sizeof(diller_cards), "LenOfCards", NULL);
	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

void CMFCApplication1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок.  Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void CMFCApplication1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // контекст устройства для рисования

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Выравнивание значка по центру клиентского прямоугольника
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Нарисуйте значок
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}

}

// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR CMFCApplication1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCApplication1Dlg::OnBnClickedOk()
{
	// TODO: добавьте свой код обработчика уведомлений
	CDialogEx::OnOK();
}

char* _GetResult(char* diller, char* user) {
	if (strlen(user) >= 10 || strlen(diller) >= 10)
		return (char*)"Ошибка!";
	//8<
	else if (strcmp(user, "8<") == 0)
		return (char*)results[0];
	//9
	else if (strcmp(user, "9") == 0) {
		if (strcmp(diller, "3") == 0 || strcmp(diller, "4") == 0 || strcmp(diller, "5") == 0 || strcmp(diller, "6") == 0)
			return (char*)results[2];
		else
			return (char*)results[0];
	}
	//10
	else if (strcmp(user, "10") == 0) {
		if (strcmp(diller, "10") == 0 || strcmp(diller, "A") == 0)
			return (char*)results[0];
		else
			return (char*)results[2];

	}
	//11
	else if (strcmp(user, "11") == 0) {
		if (strcmp(diller, "A") == 0)
			return (char*)results[0];
		else
			return (char*)results[2];

	}
	//12
	else if (strcmp(user, "12") == 0) {
		if (strcmp(diller, "4") == 0 || strcmp(diller, "5") == 0 || strcmp(diller, "6") == 0)
			return (char*)results[1];
		else
			return (char*)results[0];

	}
	//13/14/15/16
	else if (strcmp(user, "13") == 0 || strcmp(user, "14") == 0 || strcmp(user, "15") == 0 || strcmp(user, "16") == 0) {
		if (strcmp(diller, "2") == 0 || strcmp(diller, "3") == 0 || strcmp(diller, "4") == 0 || strcmp(diller, "5") == 0 || strcmp(diller, "6") == 0)
			return (char*)results[1];
		else
			return (char*)results[0];
	}
	//>17/A-8/10-10
	else if (strcmp(user, ">17") == 0 || strcmp(user, "A-8") == 0 || strcmp(user, "10-10") == 0) {
		return (char*)results[1];
	}
	//A-7
	else if (strcmp(user, "A-7") == 0) {
		if (strcmp(diller, "2") == 0 || strcmp(diller, "7") == 0 || strcmp(diller, "8") == 0)
			return (char*)results[1];
		else if (strcmp(diller, "3") == 0 || strcmp(diller, "4") == 0 || strcmp(diller, "5") == 0 || strcmp(diller, "6") == 0)
			return (char*)results[2];
		else
			return (char*)results[0];
	}
	//A-6
	else if (strcmp(user, "A-6") == 0) {
		if (strcmp(diller, "3") == 0 || strcmp(diller, "4") == 0 || strcmp(diller, "5") == 0 || strcmp(diller, "6") == 0)
			return (char*)results[2];
		else
			return (char*)results[0];
	}
	//A-5/A-4
	else if (strcmp(user, "A-5") == 0 || strcmp(user, "A-4") == 0) {
		if (strcmp(diller, "4") == 0 || strcmp(diller, "5") == 0 || strcmp(diller, "6") == 0)
			return (char*)results[2];
		else
			return (char*)results[0];
	}
	//A-3/A-2
	else if (strcmp(user, "A-3") == 0 || strcmp(user, "A-2") == 0) {
		if (strcmp(diller, "5") == 0 || strcmp(diller, "6") == 0)
			return (char*)results[2];
		else
			return (char*)results[0];

	}
	//A-A/8-8
	else if (strcmp(user, "A-A") == 0) {
		if (strcmp(diller, "A") == 0)
			return (char*)results[0];
		else
			return (char*)results[3];

	}
	//9-9
	else if (strcmp(user, "9-9") == 0) {
		if (strcmp(diller, "7") == 0 || strcmp(diller, "10") == 0 || strcmp(diller, "A") == 0)
			return (char*)results[1];
		else
			return (char*)results[3];
	}
	//8-8
	else if (strcmp(user, "8-8") == 0) {
		if (strcmp(diller, "A") == 0)
			return (char*)results[0];
		else
			return (char*)results[3];

	}
	//7-7/6-6
	else if (strcmp(user, "7-7") == 0 || (strcmp(user, "6-6") == 0)) {
	if (strcmp(diller, "8") == 0 || strcmp(diller, "9") == 0 || strcmp(diller, "10") == 0 || strcmp(diller, "A") == 0)
		return (char*)results[0];
	else
		return (char*)results[3];
	}
	//5-5
	else if (strcmp(user, "5-5") == 0) {
	if (strcmp(diller, "10") == 0 || strcmp(diller, "A") == 0)
		return (char*)results[0];
	else
		return (char*)results[2];

	}
	//4-4
	else if (strcmp(user, "4-4") == 0) {
	if (strcmp(diller, "5") == 0 || strcmp(diller, "6") == 0)
		return (char*)results[3];
	else
		return (char*)results[0];

	}
	else if (strcmp(user, "3-3,2-2") == 0) {
	if (strcmp(diller, "8") == 0 || strcmp(diller, "9") == 0 || strcmp(diller, "10") == 0 || strcmp(diller, "A") == 0)
		return (char*)results[0];
	else
		return (char*)results[3];
}

	else {
	return (char*)"Необработанная комбинация!";
	}
}
void CMFCApplication1Dlg::OnBnClickedButton1()
{
	// TODO: добавьте свой код обработчика уведомлений
	CComboBox *combo_diller = (CComboBox *)GetDlgItem(IDC_COMBO1);
	CComboBox *combo_user = (CComboBox *)GetDlgItem(IDC_COMBO2);
	char* combo_dillertxt = (char*)malloc(MAX_PATH);
	char* combo_usertxt = (char*)malloc(MAX_PATH);
	combo_user->GetLBText(combo_user->GetCurSel(), combo_usertxt);
	combo_diller->GetLBText(combo_diller->GetCurSel(), combo_dillertxt);
	CStatic* label = (CStatic*)GetDlgItem(IDC_STATIC_MY1);
	char* result = (char*)malloc(MAX_PATH);
	strcpy(result, "            Результат:\n		");
	strcat(result, _GetResult(combo_dillertxt, combo_usertxt));

	label->SetWindowText(result);

}
void CMFCApplication1Dlg::OnBnClickedButton2()
{
	// TODO: добавьте свой код обработчика уведомлений
	CAboutDlg dlgAbout;
	dlgAbout.DoModal();
	//GetDlgItem(IDC_COMBO1, AfxGetApp()->m_pMainWnd);
}


void CMFCApplication1Dlg::OnLbnSelchangeList1()
{
	// TODO: Add your control notification handler code here
	//MessageBox("Test", (LPCTSTR)"CaptionTest", NULL);
	
}


void CMFCApplication1Dlg::OnLbnSelchangeList2()
{
	// TODO: добавьте свой код обработчика уведомлений
}


void CMFCApplication1Dlg::OnStnClickedStaticMy1()
{
	// TODO: добавьте свой код обработчика уведомлений
}
