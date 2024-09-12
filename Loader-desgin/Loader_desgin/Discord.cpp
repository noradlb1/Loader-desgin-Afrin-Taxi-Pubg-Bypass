#include "Discord.h"
#include "chrono"
#include "Discord SDK/include/discord_rpc.h"


void Discord::Initialize()
{
    DiscordEventHandlers Handle;
    memset(&Handle, 0, sizeof(Handle));
    Discord_Initialize("1229844782247841872", &Handle, 1, NULL); //PARADISE

}

void Discord::Update()
{
    static int64_t StartTime = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    DiscordRichPresence discordPresence;
    memset(&discordPresence, 0, sizeof(discordPresence));
    discordPresence.state = "PubgMobile 32bit";
    discordPresence.details = ">>> TAXI HACKER <<<";
    discordPresence.startTimestamp = StartTime;
    discordPresence.endTimestamp = NULL;
    discordPresence.largeImageKey = "https://media1.tenor.com/m/AGEPCGlHKbcAAAAC/afri-vip.gif";
    discordPresence.largeImageText = "";
    discordPresence.smallImageKey = "https://media1.tenor.com/m/DaD6cpAkZhoAAAAC/nike.gif";
    discordPresence.button1Label = "Join Discord";
    discordPresence.button1Url = "https://discord.gg/KSyhzrEzQC";
    discordPresence.button2Label = "Join Telegram";
    discordPresence.button2Url = "https://t.me/+UD5H--3Np0I5NmE0";
    discordPresence.instance = 2;
    Discord_UpdatePresence(&discordPresence);
}