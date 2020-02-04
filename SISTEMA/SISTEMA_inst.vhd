	component SISTEMA is
		port (
			clk_clk                     : in  std_logic := 'X'; -- clk
			ldr_external_interface_sclk : out std_logic;        -- sclk
			ldr_external_interface_cs_n : out std_logic;        -- cs_n
			ldr_external_interface_dout : in  std_logic := 'X'; -- dout
			ldr_external_interface_din  : out std_logic;        -- din
			reset_reset_n               : in  std_logic := 'X'  -- reset_n
		);
	end component SISTEMA;

	u0 : component SISTEMA
		port map (
			clk_clk                     => CONNECTED_TO_clk_clk,                     --                    clk.clk
			ldr_external_interface_sclk => CONNECTED_TO_ldr_external_interface_sclk, -- ldr_external_interface.sclk
			ldr_external_interface_cs_n => CONNECTED_TO_ldr_external_interface_cs_n, --                       .cs_n
			ldr_external_interface_dout => CONNECTED_TO_ldr_external_interface_dout, --                       .dout
			ldr_external_interface_din  => CONNECTED_TO_ldr_external_interface_din,  --                       .din
			reset_reset_n               => CONNECTED_TO_reset_reset_n                --                  reset.reset_n
		);

