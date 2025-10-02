#include <wx/wx.h>
#include <wx/textctrl.h>
#include <wx/button.h>
#include <wx/listbox.h>
#include <string>

class MessengerFrame : public wxFrame {
public:
    MessengerFrame() : wxFrame(nullptr, wxID_ANY, "UCIC4 Messenger", wxDefaultPosition, wxSize(800, 600)) {
        // ������� ������
        wxPanel* panel = new wxPanel(this);

        // ������ ���������
        contactList = new wxListBox(panel, wxID_ANY, wxPoint(10, 10), wxSize(200, 500));

        // ���� ��� ����� ���������
        messageInput = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(220, 500), wxSize(400, 30));

        // ������ ��������
        sendButton = new wxButton(panel, wxID_ANY, "Send", wxPoint(630, 500), wxSize(100, 30));
        sendButton->Bind(wxEVT_BUTTON, &MessengerFrame::OnSend, this);

        // ���� ��� ����������� ���������
        messageLog = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(220, 10), wxSize(510, 480), wxTE_MULTILINE | wxTE_READONLY);
    }

private:
    wxListBox* contactList;
    wxTextCtrl* messageInput;
    wxButton* sendButton;
    wxTextCtrl* messageLog;

    void OnSend(wxCommandEvent& event) {
        wxString message = messageInput->GetValue();
        if (!message.IsEmpty()) {
            // ���������� ��������� (����� ���������� ������� ��������)
            SendMessageToBackend(message.ToStdString());

            // ��������� ��������� � ���
            messageLog->AppendText("You: " + message + "\n");

            // ������� ���� �����
            messageInput->Clear();
        }
    }

    void SendMessageToBackend(const std::string& message) {
        // ����� ���������� ������� �������� ��������� � ������
        // ��������, ����� ������ ��� ������ ����� IPC
        std::cout << "Sending message to backend: " << message << std::endl;
    }
};

class MessengerApp : public wxApp {
public:
    virtual bool OnInit() {
        MessengerFrame* frame = new MessengerFrame();
        frame->Show(true);
        return true;
    }
};

wxIMPLEMENT_APP(MessengerApp);
