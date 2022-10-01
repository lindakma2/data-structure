using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp1
{
    public partial class Form1 : Form
    {
        public int[,] maze = new int[1000, 1000];
        int success = 0;
        public int visit(int x,int y,int size)
        {
            int end = size - 2;
            
            //該點走過，標記為1
            maze[x,y] = 1;
            //走到終點，成功
            if (x == end && y == end)
            {
                success = 1;
            }
            //向四個方向遞迴呼叫函式visit()
            if (success != 1 && maze[x, y + 1] == 0)
            {
                visit(x, y + 1, size);
            }
            if (success != 1 && maze[x + 1, y] == 0)
            {
                visit(x + 1, y, size);
            }
            if (success != 1 && maze[x, y - 1] == 0)
            {
                visit(x, y - 1, size);
            }
            if (success != 1 && maze[x - 1, y] == 0)
            {
                visit(x - 1, y, size);
            }

            //該點走過，但沒成功，則該點重新置為0
            if (success != 1)
                maze[x,y] = 0;

            return success;
        }

        public void clear(int size)
        {
            for(int i=0;i<size;i++)
            {
                for(int j=0;j<size;j++)
                {
                    if(maze[i,j]==1)
                    {
                        maze[i, j] = 0;
                    }
                }
            }
        }

        public void walkmaze(int size)
        {
            ///walk
            ///printmaze(size, 1);
            /*int visitint = visit(0, 0, size, size);
            string StepString = visitint.ToString();
            MessageBox.Show(StepString);*/
            visit(1, 1,size);           
        }
        public void printmaze(int size)
        {
            int step=0;
            String finalresult="";
            for (int i=0;i<size;i++)
            {                            
                for (int j=0;j<size;j++)
                {
                    if(maze[i,j]==0)
                    {

                        finalresult+="o";
                    }
                    if (maze[i, j] == 2)
                    {
                        
                        
                        finalresult += "X";
                    }
                    if (maze[i, j] == 1)
                    {
                        step++;
                        ///MessageBox.Show("*");
                        finalresult += "#";
                    }
                }
                finalresult += "\r\n";
            }
            string StepString = step.ToString();
            MessageBox.Show(finalresult + "total step is " + StepString);
        }

        public Form1()
        {
            InitializeComponent();
        }

        private void Btnstart_Click(object sender, EventArgs e)
        {
            Random RandomNum = new Random();//亂數種子
            int size = (int)SizeChooser.Value;
            for(int i=0;i<size;i++)
            {
                for(int j=0;j<size;j++)
                {
                    int box = RandomNum.Next(0, 20);
                    if(i==0||i==size-1)
                    {
                        maze[i, j] = 2;
                    }
                    else if(j==size-1||j==0)
                    {
                        maze[i, j] = 2;
                    }
                    else 
                    {
                        if(box%5==1)
                        {
                            maze[i, j] = 2;
                        }
                        else
                        {
                            maze[i, j] = 0;
                        }
                    }
                }
            }
            walkmaze(size);
            printmaze(size);
        }

        private void button1_Click(object sender, EventArgs e)
        {
            int size = (int)SizeChooser.Value;
            int row = (int)RowChooser.Value;
            int column = (int)ColumnChooser.Value;
            success = 0;
            if(maze[row,column]==0|| maze[row, column] == 1)
            {                         
                maze[row, column] = 2;              
            }
            else if (maze[row, column] == 2)
            {
                maze[row, column] = 0;
            }
            clear(size);
            walkmaze(size);
            printmaze(size);
        }

        
    }
}
