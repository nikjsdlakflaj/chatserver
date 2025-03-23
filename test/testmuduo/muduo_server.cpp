/*服务器类，基于muduo库开发
*/
#include <muduo/net/TcpServer.h>    // TcpServer 类
#include <muduo/net/EventLoop.h>    // EventLoop 类
#include <muduo/net/InetAddress.h>  // InetAddress 类
#include <muduo/net/TcpConnection.h>// TcpConnectionPtr 类型
#include <muduo/net/Buffer.h>       // Buffer 类
#include <muduo/base/Timestamp.h>   // Timestamp 类型
#include <functional> 
using namespace std; 
using namespace placeholders;
using namespace muduo;
using namespace muduo::net;
class ChatServer
{
public:
// 初始化TcpServer
ChatServer(muduo::net::EventLoop *loop,
const muduo::net::InetAddress &listenAddr)
:_server(loop, listenAddr, "ChatServer")
{
// 通过绑定器设置回调函数
_server.setConnectionCallback(bind(&ChatServer::onConnection,
this, _1));
_server.setMessageCallback(bind(&ChatServer::onMessage,
this, _1, _2, _3));
// 设置EventLoop的线程个数
_server.setThreadNum(10);
}
// 启动ChatServer服务
void start()
{
_server.start();
}
private:
// TcpServer绑定的回调函数，当有新连接或连接中断时调用
void onConnection(const muduo::net::TcpConnectionPtr &con);
// TcpServer绑定的回调函数，当有新数据时调用
void onMessage(const muduo::net::TcpConnectionPtr &con,
muduo::net::Buffer *buf,
muduo::Timestamp time);
private:
muduo::net::TcpServer _server;
EventLoop *loop;
};
int main(){

EventLoop loop; 


}