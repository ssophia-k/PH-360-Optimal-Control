    function targMap = targDataMap(),

    ;%***********************
    ;% Create Parameter Map *
    ;%***********************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 7;
        sectIdxOffset = 0;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc paramMap
        ;%
        paramMap.nSections           = nTotSects;
        paramMap.sectIdxOffset       = sectIdxOffset;
            paramMap.sections(nTotSects) = dumSection; %prealloc
        paramMap.nTotData            = -1;

        ;%
        ;% Auto data (lqg_test_P)
        ;%
            section.nData     = 12;
            section.data(12)  = dumData; %prealloc

                    ;% lqg_test_P.Jp_cm
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% lqg_test_P.K_new
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% lqg_test_P.Rm
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 5;

                    ;% lqg_test_P.g
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 6;

                    ;% lqg_test_P.kt
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 7;

                    ;% lqg_test_P.l
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 8;

                    ;% lqg_test_P.mp
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 9;

                    ;% lqg_test_P.mr
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 10;

                    ;% lqg_test_P.r
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 11;

                    ;% lqg_test_P.EnableBalanceControl_const
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 12;

                    ;% lqg_test_P.kemsJ_gain
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 13;

                    ;% lqg_test_P.ErmJ_gain
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 14;

            nTotData = nTotData + section.nData;
            paramMap.sections(1) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% lqg_test_P.HILWriteAnalog_channels
                    section.data(1).logicalSrcIdx = 12;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(2) = section;
            clear section

            section.nData     = 54;
            section.data(54)  = dumData; %prealloc

                    ;% lqg_test_P.Lykyhatkk1_Y0
                    section.data(1).logicalSrcIdx = 13;
                    section.data(1).dtTransOffset = 0;

                    ;% lqg_test_P.ImpulseAmplitude_Gain
                    section.data(2).logicalSrcIdx = 14;
                    section.data(2).dtTransOffset = 1;

                    ;% lqg_test_P.utrue0estimate_Threshold
                    section.data(3).logicalSrcIdx = 15;
                    section.data(3).dtTransOffset = 2;

                    ;% lqg_test_P.ConverttoVector_Gain
                    section.data(4).logicalSrcIdx = 16;
                    section.data(4).dtTransOffset = 3;

                    ;% lqg_test_P.HILInitialize_OOTerminate
                    section.data(5).logicalSrcIdx = 17;
                    section.data(5).dtTransOffset = 7;

                    ;% lqg_test_P.HILInitialize_OOExit
                    section.data(6).logicalSrcIdx = 18;
                    section.data(6).dtTransOffset = 8;

                    ;% lqg_test_P.HILInitialize_OOStart
                    section.data(7).logicalSrcIdx = 19;
                    section.data(7).dtTransOffset = 9;

                    ;% lqg_test_P.HILInitialize_OOEnter
                    section.data(8).logicalSrcIdx = 20;
                    section.data(8).dtTransOffset = 10;

                    ;% lqg_test_P.HILInitialize_AOFinal
                    section.data(9).logicalSrcIdx = 21;
                    section.data(9).dtTransOffset = 11;

                    ;% lqg_test_P.HILInitialize_OOFinal
                    section.data(10).logicalSrcIdx = 22;
                    section.data(10).dtTransOffset = 12;

                    ;% lqg_test_P.HILInitialize_AIHigh
                    section.data(11).logicalSrcIdx = 23;
                    section.data(11).dtTransOffset = 15;

                    ;% lqg_test_P.HILInitialize_AILow
                    section.data(12).logicalSrcIdx = 24;
                    section.data(12).dtTransOffset = 16;

                    ;% lqg_test_P.HILInitialize_AOHigh
                    section.data(13).logicalSrcIdx = 25;
                    section.data(13).dtTransOffset = 17;

                    ;% lqg_test_P.HILInitialize_AOLow
                    section.data(14).logicalSrcIdx = 26;
                    section.data(14).dtTransOffset = 18;

                    ;% lqg_test_P.HILInitialize_AOInitial
                    section.data(15).logicalSrcIdx = 27;
                    section.data(15).dtTransOffset = 19;

                    ;% lqg_test_P.HILInitialize_AOWatchdog
                    section.data(16).logicalSrcIdx = 28;
                    section.data(16).dtTransOffset = 20;

                    ;% lqg_test_P.HILInitialize_OOInitial
                    section.data(17).logicalSrcIdx = 29;
                    section.data(17).dtTransOffset = 21;

                    ;% lqg_test_P.HILInitialize_OOWatchdog
                    section.data(18).logicalSrcIdx = 30;
                    section.data(18).dtTransOffset = 24;

                    ;% lqg_test_P.Pendulumcountstorad_Gain
                    section.data(19).logicalSrcIdx = 31;
                    section.data(19).dtTransOffset = 27;

                    ;% lqg_test_P.Constant2_Value
                    section.data(20).logicalSrcIdx = 32;
                    section.data(20).dtTransOffset = 28;

                    ;% lqg_test_P.Bias_Bias
                    section.data(21).logicalSrcIdx = 33;
                    section.data(21).dtTransOffset = 29;

                    ;% lqg_test_P.Armcountstorad_Gain
                    section.data(22).logicalSrcIdx = 34;
                    section.data(22).dtTransOffset = 30;

                    ;% lqg_test_P.theta_dot_A
                    section.data(23).logicalSrcIdx = 35;
                    section.data(23).dtTransOffset = 31;

                    ;% lqg_test_P.theta_dot_C
                    section.data(24).logicalSrcIdx = 36;
                    section.data(24).dtTransOffset = 32;

                    ;% lqg_test_P.theta_dot_D
                    section.data(25).logicalSrcIdx = 37;
                    section.data(25).dtTransOffset = 33;

                    ;% lqg_test_P.alpha_dot_A
                    section.data(26).logicalSrcIdx = 38;
                    section.data(26).dtTransOffset = 34;

                    ;% lqg_test_P.alpha_dot_C
                    section.data(27).logicalSrcIdx = 39;
                    section.data(27).dtTransOffset = 35;

                    ;% lqg_test_P.alpha_dot_D
                    section.data(28).logicalSrcIdx = 40;
                    section.data(28).dtTransOffset = 36;

                    ;% lqg_test_P.Gain_Gain
                    section.data(29).logicalSrcIdx = 41;
                    section.data(29).dtTransOffset = 37;

                    ;% lqg_test_P.Gain_Gain_i
                    section.data(30).logicalSrcIdx = 42;
                    section.data(30).dtTransOffset = 38;

                    ;% lqg_test_P.SignalGenerator_Amplitude
                    section.data(31).logicalSrcIdx = 43;
                    section.data(31).dtTransOffset = 39;

                    ;% lqg_test_P.SignalGenerator_Frequency
                    section.data(32).logicalSrcIdx = 44;
                    section.data(32).dtTransOffset = 40;

                    ;% lqg_test_P.Gain_Gain_e
                    section.data(33).logicalSrcIdx = 45;
                    section.data(33).dtTransOffset = 41;

                    ;% lqg_test_P.Gain1_Gain
                    section.data(34).logicalSrcIdx = 46;
                    section.data(34).dtTransOffset = 42;

                    ;% lqg_test_P.Gain_Gain_a
                    section.data(35).logicalSrcIdx = 47;
                    section.data(35).dtTransOffset = 43;

                    ;% lqg_test_P.Step_Time
                    section.data(36).logicalSrcIdx = 48;
                    section.data(36).dtTransOffset = 44;

                    ;% lqg_test_P.Step_Y0
                    section.data(37).logicalSrcIdx = 49;
                    section.data(37).dtTransOffset = 45;

                    ;% lqg_test_P.Step_YFinal
                    section.data(38).logicalSrcIdx = 50;
                    section.data(38).dtTransOffset = 46;

                    ;% lqg_test_P.Step1_Time
                    section.data(39).logicalSrcIdx = 51;
                    section.data(39).dtTransOffset = 47;

                    ;% lqg_test_P.Step1_Y0
                    section.data(40).logicalSrcIdx = 52;
                    section.data(40).dtTransOffset = 48;

                    ;% lqg_test_P.Step1_YFinal
                    section.data(41).logicalSrcIdx = 53;
                    section.data(41).dtTransOffset = 49;

                    ;% lqg_test_P.u_max_Value
                    section.data(42).logicalSrcIdx = 54;
                    section.data(42).dtTransOffset = 50;

                    ;% lqg_test_P.Constant_Value
                    section.data(43).logicalSrcIdx = 55;
                    section.data(43).dtTransOffset = 51;

                    ;% lqg_test_P.Constant_Value_o
                    section.data(44).logicalSrcIdx = 56;
                    section.data(44).dtTransOffset = 52;

                    ;% lqg_test_P.mJtoJ_Gain
                    section.data(45).logicalSrcIdx = 57;
                    section.data(45).dtTransOffset = 53;

                    ;% lqg_test_P.Constant_Value_g
                    section.data(46).logicalSrcIdx = 58;
                    section.data(46).dtTransOffset = 54;

                    ;% lqg_test_P.A_Value
                    section.data(47).logicalSrcIdx = 59;
                    section.data(47).dtTransOffset = 55;

                    ;% lqg_test_P.B_Value
                    section.data(48).logicalSrcIdx = 60;
                    section.data(48).dtTransOffset = 71;

                    ;% lqg_test_P.C_Value
                    section.data(49).logicalSrcIdx = 61;
                    section.data(49).dtTransOffset = 75;

                    ;% lqg_test_P.CovarianceZ_Value
                    section.data(50).logicalSrcIdx = 62;
                    section.data(50).dtTransOffset = 83;

                    ;% lqg_test_P.KalmanGainL_Value
                    section.data(51).logicalSrcIdx = 63;
                    section.data(51).dtTransOffset = 99;

                    ;% lqg_test_P.D_Value
                    section.data(52).logicalSrcIdx = 64;
                    section.data(52).dtTransOffset = 107;

                    ;% lqg_test_P.ForveCCW_Gain
                    section.data(53).logicalSrcIdx = 65;
                    section.data(53).dtTransOffset = 109;

                    ;% lqg_test_P.JtomJ_Gain
                    section.data(54).logicalSrcIdx = 66;
                    section.data(54).dtTransOffset = 110;

            nTotData = nTotData + section.nData;
            paramMap.sections(3) = section;
            clear section

            section.nData     = 4;
            section.data(4)  = dumData; %prealloc

                    ;% lqg_test_P.HILInitialize_CKChannels
                    section.data(1).logicalSrcIdx = 67;
                    section.data(1).dtTransOffset = 0;

                    ;% lqg_test_P.HILInitialize_DOWatchdog
                    section.data(2).logicalSrcIdx = 68;
                    section.data(2).dtTransOffset = 1;

                    ;% lqg_test_P.HILInitialize_EIInitial
                    section.data(3).logicalSrcIdx = 69;
                    section.data(3).dtTransOffset = 2;

                    ;% lqg_test_P.HILReadEncoderTimebase_Clock
                    section.data(4).logicalSrcIdx = 70;
                    section.data(4).dtTransOffset = 3;

            nTotData = nTotData + section.nData;
            paramMap.sections(4) = section;
            clear section

            section.nData     = 10;
            section.data(10)  = dumData; %prealloc

                    ;% lqg_test_P.HILInitialize_AIChannels
                    section.data(1).logicalSrcIdx = 71;
                    section.data(1).dtTransOffset = 0;

                    ;% lqg_test_P.HILInitialize_AOChannels
                    section.data(2).logicalSrcIdx = 72;
                    section.data(2).dtTransOffset = 1;

                    ;% lqg_test_P.HILInitialize_DOChannels
                    section.data(3).logicalSrcIdx = 73;
                    section.data(3).dtTransOffset = 2;

                    ;% lqg_test_P.HILInitialize_EIChannels
                    section.data(4).logicalSrcIdx = 74;
                    section.data(4).dtTransOffset = 3;

                    ;% lqg_test_P.HILInitialize_EIQuadrature
                    section.data(5).logicalSrcIdx = 75;
                    section.data(5).dtTransOffset = 5;

                    ;% lqg_test_P.HILInitialize_OOChannels
                    section.data(6).logicalSrcIdx = 76;
                    section.data(6).dtTransOffset = 6;

                    ;% lqg_test_P.HILReadEncoderTimebase_Channels
                    section.data(7).logicalSrcIdx = 77;
                    section.data(7).dtTransOffset = 9;

                    ;% lqg_test_P.HILReadEncoderTimebase_SamplesI
                    section.data(8).logicalSrcIdx = 78;
                    section.data(8).dtTransOffset = 11;

                    ;% lqg_test_P.ToHostFile_Decimation
                    section.data(9).logicalSrcIdx = 79;
                    section.data(9).dtTransOffset = 12;

                    ;% lqg_test_P.ToHostFile_BitRate
                    section.data(10).logicalSrcIdx = 80;
                    section.data(10).dtTransOffset = 13;

            nTotData = nTotData + section.nData;
            paramMap.sections(5) = section;
            clear section

            section.nData     = 39;
            section.data(39)  = dumData; %prealloc

                    ;% lqg_test_P.HILInitialize_Active
                    section.data(1).logicalSrcIdx = 81;
                    section.data(1).dtTransOffset = 0;

                    ;% lqg_test_P.HILInitialize_AOTerminate
                    section.data(2).logicalSrcIdx = 82;
                    section.data(2).dtTransOffset = 1;

                    ;% lqg_test_P.HILInitialize_AOExit
                    section.data(3).logicalSrcIdx = 83;
                    section.data(3).dtTransOffset = 2;

                    ;% lqg_test_P.HILInitialize_DOTerminate
                    section.data(4).logicalSrcIdx = 84;
                    section.data(4).dtTransOffset = 3;

                    ;% lqg_test_P.HILInitialize_DOExit
                    section.data(5).logicalSrcIdx = 85;
                    section.data(5).dtTransOffset = 4;

                    ;% lqg_test_P.HILInitialize_POTerminate
                    section.data(6).logicalSrcIdx = 86;
                    section.data(6).dtTransOffset = 5;

                    ;% lqg_test_P.HILInitialize_POExit
                    section.data(7).logicalSrcIdx = 87;
                    section.data(7).dtTransOffset = 6;

                    ;% lqg_test_P.HILInitialize_CKPStart
                    section.data(8).logicalSrcIdx = 88;
                    section.data(8).dtTransOffset = 7;

                    ;% lqg_test_P.HILInitialize_CKPEnter
                    section.data(9).logicalSrcIdx = 89;
                    section.data(9).dtTransOffset = 8;

                    ;% lqg_test_P.HILInitialize_CKStart
                    section.data(10).logicalSrcIdx = 90;
                    section.data(10).dtTransOffset = 9;

                    ;% lqg_test_P.HILInitialize_CKEnter
                    section.data(11).logicalSrcIdx = 91;
                    section.data(11).dtTransOffset = 10;

                    ;% lqg_test_P.HILInitialize_AIPStart
                    section.data(12).logicalSrcIdx = 92;
                    section.data(12).dtTransOffset = 11;

                    ;% lqg_test_P.HILInitialize_AIPEnter
                    section.data(13).logicalSrcIdx = 93;
                    section.data(13).dtTransOffset = 12;

                    ;% lqg_test_P.HILInitialize_AOPStart
                    section.data(14).logicalSrcIdx = 94;
                    section.data(14).dtTransOffset = 13;

                    ;% lqg_test_P.HILInitialize_AOPEnter
                    section.data(15).logicalSrcIdx = 95;
                    section.data(15).dtTransOffset = 14;

                    ;% lqg_test_P.HILInitialize_AOStart
                    section.data(16).logicalSrcIdx = 96;
                    section.data(16).dtTransOffset = 15;

                    ;% lqg_test_P.HILInitialize_AOEnter
                    section.data(17).logicalSrcIdx = 97;
                    section.data(17).dtTransOffset = 16;

                    ;% lqg_test_P.HILInitialize_AOReset
                    section.data(18).logicalSrcIdx = 98;
                    section.data(18).dtTransOffset = 17;

                    ;% lqg_test_P.HILInitialize_DOPStart
                    section.data(19).logicalSrcIdx = 99;
                    section.data(19).dtTransOffset = 18;

                    ;% lqg_test_P.HILInitialize_DOPEnter
                    section.data(20).logicalSrcIdx = 100;
                    section.data(20).dtTransOffset = 19;

                    ;% lqg_test_P.HILInitialize_DOStart
                    section.data(21).logicalSrcIdx = 101;
                    section.data(21).dtTransOffset = 20;

                    ;% lqg_test_P.HILInitialize_DOEnter
                    section.data(22).logicalSrcIdx = 102;
                    section.data(22).dtTransOffset = 21;

                    ;% lqg_test_P.HILInitialize_DOReset
                    section.data(23).logicalSrcIdx = 103;
                    section.data(23).dtTransOffset = 22;

                    ;% lqg_test_P.HILInitialize_EIPStart
                    section.data(24).logicalSrcIdx = 104;
                    section.data(24).dtTransOffset = 23;

                    ;% lqg_test_P.HILInitialize_EIPEnter
                    section.data(25).logicalSrcIdx = 105;
                    section.data(25).dtTransOffset = 24;

                    ;% lqg_test_P.HILInitialize_EIStart
                    section.data(26).logicalSrcIdx = 106;
                    section.data(26).dtTransOffset = 25;

                    ;% lqg_test_P.HILInitialize_EIEnter
                    section.data(27).logicalSrcIdx = 107;
                    section.data(27).dtTransOffset = 26;

                    ;% lqg_test_P.HILInitialize_POPStart
                    section.data(28).logicalSrcIdx = 108;
                    section.data(28).dtTransOffset = 27;

                    ;% lqg_test_P.HILInitialize_POPEnter
                    section.data(29).logicalSrcIdx = 109;
                    section.data(29).dtTransOffset = 28;

                    ;% lqg_test_P.HILInitialize_POStart
                    section.data(30).logicalSrcIdx = 110;
                    section.data(30).dtTransOffset = 29;

                    ;% lqg_test_P.HILInitialize_POEnter
                    section.data(31).logicalSrcIdx = 111;
                    section.data(31).dtTransOffset = 30;

                    ;% lqg_test_P.HILInitialize_POReset
                    section.data(32).logicalSrcIdx = 112;
                    section.data(32).dtTransOffset = 31;

                    ;% lqg_test_P.HILInitialize_OOReset
                    section.data(33).logicalSrcIdx = 113;
                    section.data(33).dtTransOffset = 32;

                    ;% lqg_test_P.HILInitialize_DOFinal
                    section.data(34).logicalSrcIdx = 114;
                    section.data(34).dtTransOffset = 33;

                    ;% lqg_test_P.HILInitialize_DOInitial
                    section.data(35).logicalSrcIdx = 115;
                    section.data(35).dtTransOffset = 34;

                    ;% lqg_test_P.HILReadEncoderTimebase_Active
                    section.data(36).logicalSrcIdx = 116;
                    section.data(36).dtTransOffset = 35;

                    ;% lqg_test_P.isSqrtUsed_Value
                    section.data(37).logicalSrcIdx = 117;
                    section.data(37).dtTransOffset = 36;

                    ;% lqg_test_P.Enable_Value
                    section.data(38).logicalSrcIdx = 118;
                    section.data(38).dtTransOffset = 37;

                    ;% lqg_test_P.HILWriteAnalog_Active
                    section.data(39).logicalSrcIdx = 119;
                    section.data(39).dtTransOffset = 38;

            nTotData = nTotData + section.nData;
            paramMap.sections(6) = section;
            clear section

            section.nData     = 4;
            section.data(4)  = dumData; %prealloc

                    ;% lqg_test_P.HILReadEncoderTimebase_Overflow
                    section.data(1).logicalSrcIdx = 120;
                    section.data(1).dtTransOffset = 0;

                    ;% lqg_test_P.ToHostFile_file_name
                    section.data(2).logicalSrcIdx = 121;
                    section.data(2).dtTransOffset = 1;

                    ;% lqg_test_P.ToHostFile_VarName
                    section.data(3).logicalSrcIdx = 122;
                    section.data(3).dtTransOffset = 10;

                    ;% lqg_test_P.ToHostFile_FileFormat
                    section.data(4).logicalSrcIdx = 123;
                    section.data(4).dtTransOffset = 15;

            nTotData = nTotData + section.nData;
            paramMap.sections(7) = section;
            clear section


            ;%
            ;% Non-auto Data (parameter)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        paramMap.nTotData = nTotData;



    ;%**************************
    ;% Create Block Output Map *
    ;%**************************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 3;
        sectIdxOffset = 0;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc sigMap
        ;%
        sigMap.nSections           = nTotSects;
        sigMap.sectIdxOffset       = sectIdxOffset;
            sigMap.sections(nTotSects) = dumSection; %prealloc
        sigMap.nTotData            = -1;

        ;%
        ;% Auto data (lqg_test_B)
        ;%
            section.nData     = 20;
            section.data(20)  = dumData; %prealloc

                    ;% lqg_test_B.Pendulumcountstorad
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% lqg_test_B.Bias
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% lqg_test_B.Armcountstorad
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 2;

                    ;% lqg_test_B.theta_dot
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 3;

                    ;% lqg_test_B.alpha_dot
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 4;

                    ;% lqg_test_B.ReshapeX0
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 5;

                    ;% lqg_test_B.Gain
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 9;

                    ;% lqg_test_B.Gain_m
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 11;

                    ;% lqg_test_B.Gain_b
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 13;

                    ;% lqg_test_B.SliderGain
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 16;

                    ;% lqg_test_B.PendTorqueNm
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 17;

                    ;% lqg_test_B.mJtoJ
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 18;

                    ;% lqg_test_B.cosalpha
                    section.data(13).logicalSrcIdx = 12;
                    section.data(13).dtTransOffset = 19;

                    ;% lqg_test_B.UnaryMinus
                    section.data(14).logicalSrcIdx = 13;
                    section.data(14).dtTransOffset = 20;

                    ;% lqg_test_B.EnableBalanceControlSwitch
                    section.data(15).logicalSrcIdx = 14;
                    section.data(15).dtTransOffset = 21;

                    ;% lqg_test_B.Reshapey
                    section.data(16).logicalSrcIdx = 15;
                    section.data(16).dtTransOffset = 22;

                    ;% lqg_test_B.Add
                    section.data(17).logicalSrcIdx = 16;
                    section.data(17).dtTransOffset = 24;

                    ;% lqg_test_B.ForveCCW
                    section.data(18).logicalSrcIdx = 17;
                    section.data(18).dtTransOffset = 28;

                    ;% lqg_test_B.JtomJ
                    section.data(19).logicalSrcIdx = 18;
                    section.data(19).dtTransOffset = 29;

                    ;% lqg_test_B.Product3
                    section.data(20).logicalSrcIdx = 19;
                    section.data(20).dtTransOffset = 30;

            nTotData = nTotData + section.nData;
            sigMap.sections(1) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% lqg_test_B.Compare
                    section.data(1).logicalSrcIdx = 20;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(2) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% lqg_test_B.DataTypeConversionReset
                    section.data(1).logicalSrcIdx = 21;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(3) = section;
            clear section


            ;%
            ;% Non-auto Data (signal)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        sigMap.nTotData = nTotData;



    ;%*******************
    ;% Create DWork Map *
    ;%*******************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 10;
        sectIdxOffset = 3;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc dworkMap
        ;%
        dworkMap.nSections           = nTotSects;
        dworkMap.sectIdxOffset       = sectIdxOffset;
            dworkMap.sections(nTotSects) = dumSection; %prealloc
        dworkMap.nTotData            = -1;

        ;%
        ;% Auto data (lqg_test_DW)
        ;%
            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% lqg_test_DW.HILInitialize_FilterFrequency
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(1) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% lqg_test_DW.ToHostFile_PointsWritten
                    section.data(1).logicalSrcIdx = 1;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(2) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% lqg_test_DW.HILInitialize_Card
                    section.data(1).logicalSrcIdx = 2;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(3) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% lqg_test_DW.HILReadEncoderTimebase_Task
                    section.data(1).logicalSrcIdx = 3;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(4) = section;
            clear section

            section.nData     = 7;
            section.data(7)  = dumData; %prealloc

                    ;% lqg_test_DW.Pendulumdeg_PWORK.LoggedData
                    section.data(1).logicalSrcIdx = 4;
                    section.data(1).dtTransOffset = 0;

                    ;% lqg_test_DW.PendulumangularvelocityDegs_PWO.LoggedData
                    section.data(2).logicalSrcIdx = 5;
                    section.data(2).dtTransOffset = 1;

                    ;% lqg_test_DW.RotaryArmdeg_PWORK.LoggedData
                    section.data(3).logicalSrcIdx = 6;
                    section.data(3).dtTransOffset = 2;

                    ;% lqg_test_DW.ToHostFile_PWORK
                    section.data(4).logicalSrcIdx = 7;
                    section.data(4).dtTransOffset = 3;

                    ;% lqg_test_DW.VmV_PWORK.LoggedData
                    section.data(5).logicalSrcIdx = 8;
                    section.data(5).dtTransOffset = 5;

                    ;% lqg_test_DW.HILWriteAnalog_PWORK
                    section.data(6).logicalSrcIdx = 9;
                    section.data(6).dtTransOffset = 6;

                    ;% lqg_test_DW.PendulumEnergymJ_PWORK.LoggedData
                    section.data(7).logicalSrcIdx = 10;
                    section.data(7).dtTransOffset = 7;

            nTotData = nTotData + section.nData;
            dworkMap.sections(5) = section;
            clear section

            section.nData     = 5;
            section.data(5)  = dumData; %prealloc

                    ;% lqg_test_DW.HILInitialize_ClockModes
                    section.data(1).logicalSrcIdx = 11;
                    section.data(1).dtTransOffset = 0;

                    ;% lqg_test_DW.HILInitialize_DOStates
                    section.data(2).logicalSrcIdx = 12;
                    section.data(2).dtTransOffset = 1;

                    ;% lqg_test_DW.HILInitialize_QuadratureModes
                    section.data(3).logicalSrcIdx = 13;
                    section.data(3).dtTransOffset = 2;

                    ;% lqg_test_DW.HILInitialize_InitialEICounts
                    section.data(4).logicalSrcIdx = 14;
                    section.data(4).dtTransOffset = 4;

                    ;% lqg_test_DW.HILReadEncoderTimebase_Buffer
                    section.data(5).logicalSrcIdx = 15;
                    section.data(5).dtTransOffset = 6;

            nTotData = nTotData + section.nData;
            dworkMap.sections(6) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% lqg_test_DW.ToHostFile_SamplesCount
                    section.data(1).logicalSrcIdx = 16;
                    section.data(1).dtTransOffset = 0;

                    ;% lqg_test_DW.ToHostFile_ArrayNameLength
                    section.data(2).logicalSrcIdx = 17;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            dworkMap.sections(7) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% lqg_test_DW.MemoryX_IWORK
                    section.data(1).logicalSrcIdx = 18;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(8) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% lqg_test_DW.MeasurementUpdate_SubsysRanBC
                    section.data(1).logicalSrcIdx = 19;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(9) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% lqg_test_DW.MeasurementUpdate_MODE
                    section.data(1).logicalSrcIdx = 20;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(10) = section;
            clear section


            ;%
            ;% Non-auto Data (dwork)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        dworkMap.nTotData = nTotData;



    ;%
    ;% Add individual maps to base struct.
    ;%

    targMap.paramMap  = paramMap;
    targMap.signalMap = sigMap;
    targMap.dworkMap  = dworkMap;

    ;%
    ;% Add checksums to base struct.
    ;%


    targMap.checksum0 = 1940526557;
    targMap.checksum1 = 2159894852;
    targMap.checksum2 = 1823604605;
    targMap.checksum3 = 2186527533;

