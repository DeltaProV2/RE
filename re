local Players = game:GetService("Players")

local Player = Players.LocalPlayer
local PlayerGui = Player:WaitForChild("PlayerGui")

local ScreenGui = Instance.new("ScreenGui")
ScreenGui.ResetOnSpawn = false
ScreenGui.Parent = PlayerGui

local Main = Instance.new("Frame")
Main.Size = UDim2.fromOffset(650, 500)
Main.Position = UDim2.fromScale(0.5, 0.5)
Main.AnchorPoint = Vector2.new(0.5, 0.5)
Main.BackgroundColor3 = Color3.fromRGB(8, 8, 8)
Main.BorderSizePixel = 0
Main.Parent = ScreenGui

local Corner = Instance.new("UICorner")
Corner.CornerRadius = UDim.new(0, 20)
Corner.Parent = Main

-- Top Blue Line
local TopLine = Instance.new("Frame")
TopLine.Size = UDim2.new(1, 0, 0, 6)
TopLine.BackgroundColor3 = Color3.fromRGB(0, 170, 255)
TopLine.BorderSizePixel = 0
TopLine.Parent = Main

-- Title
local Title = Instance.new("TextLabel")
Title.Size = UDim2.new(1, 0, 0, 70)
Title.Position = UDim2.new(0, 0, 0, 10)
Title.BackgroundTransparency = 1
Title.Text = "ACCESS PANEL"
Title.TextColor3 = Color3.new(1,1,1)
Title.Font = Enum.Font.GothamBold
Title.TextScaled = true
Title.Parent = Main

-- Link Text
local LinkText = Instance.new("TextLabel")
LinkText.Size = UDim2.new(1, -40, 0, 40)
LinkText.Position = UDim2.new(0, 20, 0, 100)
LinkText.BackgroundTransparency = 1
LinkText.Text = "Link copied! Paste in browser 🔗"
LinkText.TextColor3 = Color3.fromRGB(180,180,180)
LinkText.Font = Enum.Font.Gotham
LinkText.TextScaled = true
LinkText.Parent = Main

-- Instructions
local Instructions = Instance.new("TextLabel")
Instructions.Size = UDim2.new(1, -80, 0, 150)
Instructions.Position = UDim2.new(0, 40, 0, 170)
Instructions.BackgroundTransparency = 1
Instructions.TextXAlignment = Enum.TextXAlignment.Left
Instructions.TextYAlignment = Enum.TextYAlignment.Top
Instructions.Font = Enum.Font.Gotham
Instructions.TextColor3 = Color3.fromRGB(220,220,220)
Instructions.TextSize = 28
Instructions.Text =
[[1. Click JOIN GROUP
2. Link will be copied to your clipboard
3. Paste link in Chrome
4. Join group and enjoy your script]]
Instructions.Parent = Main

-- Join Button
local JoinButton = Instance.new("TextButton")
JoinButton.Size = UDim2.fromOffset(420, 70)
JoinButton.Position = UDim2.new(0.5, -210, 0, 320)
JoinButton.BackgroundColor3 = Color3.fromRGB(0, 150, 255)
JoinButton.Text = "JOIN GROUP"
JoinButton.TextColor3 = Color3.new(1,1,1)
JoinButton.Font = Enum.Font.GothamBold
JoinButton.TextScaled = true
JoinButton.Parent = Main

local ButtonCorner = Instance.new("UICorner")
ButtonCorner.CornerRadius = UDim.new(1, 0)
ButtonCorner.Parent = JoinButton

-- Footer
local Footer = Instance.new("TextLabel")
Footer.Size = UDim2.new(1, -40, 0, 30)
Footer.Position = UDim2.new(0, 20, 1, -45)
Footer.BackgroundTransparency = 1
Footer.Text = "Add your Discord here if you have any issues"
Footer.TextColor3 = Color3.fromRGB(100,100,100)
Footer.Font = Enum.Font.Gotham
Footer.TextScaled = true
Footer.Parent = Main

-- Button Function
JoinButton.MouseButton1Click:Connect(function()
	setclipboard("https://your-group-link-here")
	LinkText.Text = "Link copied! Paste in browser 🔗"
end)
