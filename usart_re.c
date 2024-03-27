if(Res==0x53)//头
		{
			u16_recv_data_index = 0; // 重新开始接收新的数据包
		}
		else if(Res==0x0d)//尾
		{
	    
		}
		else if(Res==0x0a)//尾
		{
			if(only_one==0)
			{
			USART_RX_STA=1;//接收完成标志
			}		
//			memset(USART_RX_BUF, 0, u16_recv_data_index);
      u16_recv_data_index = 0;//指针归零
		}
		else
		{
			// 判断数据包长度是否超出了数组的最大长度
       if (u16_recv_data_index < USART_REC_LEN)
       {
          USART_RX_BUF[u16_recv_data_index++] = Res; // 将数据存放到数组中
       }
			 else
			 {
				 u16_recv_data_index = 0;
			 }
            
		}