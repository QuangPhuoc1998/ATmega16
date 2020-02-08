using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
// sử dụng serial port
using System.IO;
using System.IO.Ports;
using System.Xml;

namespace Visual_Studio_HC_05
{
    public partial class Form1 : Form
    {
        SerialPort P = new SerialPort(); // Khai báo 1 Object SerialPort mới.
        string InputData = String.Empty; // Khai báo string buff dùng cho hiển thị dữ liệu sau này.
        delegate void SetTextCallback(string text); // Khai bao delegate SetTextCallBack voi tham so string
        public Form1()
        {
            InitializeComponent();
            // Cài đặt các thông số cho COM
            // Mảng string port để chứ tất cả các cổng COM đang có trên máy tính
            string[] ports = SerialPort.GetPortNames();
            // Thêm toàn bộ các COM đã tìm được vào combox cbCom
            cbCom.Items.AddRange(ports); // Sử dụng AddRange thay vì dùng foreach 
            P.ReadTimeout = 1000;
            // P.DataReceived += new SerialDataReceivedEventHandler(DataReceive);
            // Cài đặt cho BaudRate
            string[] BaudRate = { "1200", "2400", "4800", "9600", "19200", "38400", "57600", "115200" };
            cbRate.Items.AddRange(BaudRate);
            // Cài đặt cho DataBits
            string[] Databits = { "6", "7", "8" };
            cbData.Items.AddRange(Databits);
            //Cho Parity
            string[] Parity = { "None", "Odd", "Even" };
            cbParity.Items.AddRange(Parity);
            //Cho Stop bit
            string[] stopbit = { "1", "1.5", "2" };
            cbStop.Items.AddRange(stopbit);
            // cài đặt cho Prescaler
            string[] prescaler = {"1/1", "1/2", "1/4", "1/8", "1/16"};
            cbPre.Items.AddRange(prescaler);
            // cài đặt cho Dir
            string[] Dir = {"Right","Left"};
            cbDir.Items.AddRange(Dir);
        }

        private void groupBox1_Enter(object sender, EventArgs e)
        {

        }

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void label5_Click(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            try
            {
                P.Open();
                btNgat.Enabled = true;
                btKetnoi.Enabled = false;
                groupBox1.Enabled = false;
                groupBox4.Enabled = true;
            }
            catch (Exception ex)
            {
                MessageBox.Show("Khong ket noi duoc.", "Thu lai", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            if (P.IsOpen)
            {
                //P.Write("s\r");
            }
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            cbCom.SelectedIndex = 0; // chọn COM được tìm thấy đầu tiên
            cbRate.SelectedIndex = 3; // 9600
            cbData.SelectedIndex = 2; // 8
            cbParity.SelectedIndex = 0; // None
            cbStop.SelectedIndex = 0; // None
            cbPre.SelectedIndex = 0; // 1/1
            cbDir.SelectedIndex = 0; // right
            groupBox4.Enabled = false;
        }

        private void cbCom_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (P.IsOpen)
            {
                P.Close(); // Nếu đang mở Port thì phải đóng lại
            }
            P.PortName = cbCom.SelectedItem.ToString(); // Gán PortName bằng COM đã chọn
        }

        private void cbRate_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (P.IsOpen)
            {
                P.Close();
            }
            P.BaudRate = Convert.ToInt32(cbRate.Text);
        }

        private void cbData_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (P.IsOpen)
            {
                P.Close();
            }
            P.DataBits = Convert.ToInt32(cbData.Text);
        }

        private void cbParity_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (P.IsOpen)
            {
                P.Close();
            }
            switch (cbParity.SelectedItem.ToString())
            {
                case "Odd":
                    P.Parity = Parity.Odd;
                    break;
                case "None":
                    P.Parity = Parity.None;
                    break;
                case "Even":
                    P.Parity = Parity.Even;
                    break;
            }
        }

        private void cbStop_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (P.IsOpen)
            {
                P.Close();
            }
            switch (cbStop.SelectedItem.ToString())
            {
                case "1":
                    P.StopBits = StopBits.One;
                    break;
                case "1.5":
                    P.StopBits = StopBits.OnePointFive;
                    break;
                case "2":
                    P.StopBits = StopBits.Two;
                    break;
            }
        }
        private void btNgat_Click(object sender, EventArgs e)
        {
            P.Write("e");
            P.Close();
            btKetnoi.Enabled = true;
            btNgat.Enabled = false;
            groupBox1.Enabled = true;
            groupBox4.Enabled = false;
        }

        private void btThoat_Click(object sender, EventArgs e)
        {
            DialogResult kq = MessageBox.Show("Ban thuc su muon thoat", "Neko_chan", MessageBoxButtons.YesNo, MessageBoxIcon.Question);
            if (kq == DialogResult.Yes)
            {
                MessageBox.Show("Cam on ban da su dung chuong trinh", "Neko_chan");
                P.Close();
                this.Close();
            }
        }

        

        private void button1_Click_1(object sender, EventArgs e)
        {
            if (P.IsOpen == true)
            {
                P.Write("0");
            }
            else
            {
                MessageBox.Show("chưa mở cổng COM");
            }
        }
        private void button2_Click(object sender, EventArgs e)
        {
            
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void LED1_Click(object sender, EventArgs e)
        {
            if (P.IsOpen == true)
            {
                P.Write("a");
            }
            else
            {
                MessageBox.Show("chưa mở cổng COM");
            }
        }

        private void button8_Click(object sender, EventArgs e)
        {
            if (P.IsOpen == true)
            {
                P.Write("s");
            }
            else
            {
                MessageBox.Show("chưa mở cổng COM");
            }
        }

        private void button9_Click(object sender, EventArgs e)
        {
            if (P.IsOpen == true)
            {
                P.Write("s");
            }
            else
            {
                MessageBox.Show("chưa mở cổng COM");
            }
        }
        private void btn_send_Click(object sender, EventArgs e)
        {
            if (P.IsOpen == true)
            {
                //
                if (cbPre.Text == "1/1") P.Write("F\r");
                else if (cbPre.Text == "1/2") P.Write("H\r");
                else if (cbPre.Text == "1/4") P.Write("Q\r");
                else if (cbPre.Text == "1/8") P.Write("E\r");
                else if (cbPre.Text == "1/16") P.Write("S\r");
                //      
                if (cbDir.Text == "Right") P.Write("R\r");
                else if (cbDir.Text == "Left") P.Write("L\r");
                //
                P.Write(txt_send.Text + "\r");
            }
            else
            {
                MessageBox.Show("chưa mở cổng COM");
            }
        }

        private void txt_send_TextChanged(object sender, EventArgs e)
        {

        }

        private void label9_Click(object sender, EventArgs e)
        {

        }

        private void button2_Click_1(object sender, EventArgs e)
        {
            if (P.IsOpen == true)
            {
                P.Write("1");
            }
            else
            {
                MessageBox.Show("chưa mở cổng COM");
            }
        }

        private void button1_Click_2(object sender, EventArgs e)
        {
            if (P.IsOpen == true)
            {
                P.Write("2");
            }
            else
            {
                MessageBox.Show("chưa mở cổng COM");
            }
        }

        private void statusStrip1_ItemClicked(object sender, ToolStripItemClickedEventArgs e)
        {

        }

        private void serialPort1_DataReceived(object sender, SerialDataReceivedEventArgs e)
        {

        }
        /*
Action<string> serialPortReceiverAction;
private void P_DataReceived(object sender, SerialDataReceivedEventArgs e)
{
   serialPortReceiverAction = serialPortReceiver;
   try
   {
       this.BeginInvoke(serialPortReceiverAction, P.ReadExisting());
   }
   catch { }
}
private void serialPortReceiver(string input)
{
   txtDataReceiver.Text += input;
}
*/
    }
}
